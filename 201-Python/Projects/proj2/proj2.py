"""
File:    proj2.py
Author:  Denish Pasupuleti
Date:    Oct 31 2019
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This is an adaptation of the pen and paper game sim
two players must take turns inputting coordinates and the goal is
not to make a triangle with your chosen variable.
"""
from proj2_ui import print_board

# constants
GRID = 6
P1 = 1
P2 = 2
MAX = 6
MIN = 0


def get_symbol(player):
    """
    gets symbols for players

    :param player: player number
    :return: returns symbol
    """
    symbol = input("Hello, What character would player " + str(player) + " like to use? ")
    symbol.strip().split()
    while len(symbol) > 1:
        print("Please enter a single character")
        symbol = input("Hello, What character would player " + str(player) + " like to use? ")
        symbol.strip().split()
    return symbol


def get_coordinates(player):
    """
    prompts for two points

    :param player: which player is playing
    :returns: list in which the coordinates are in [x,y]
    """
    line = input("Enter a line for player " + str(player) + ": ")
    # strips whitespace and splits into list with 2 values
    line = line.strip().split()
    # makes sure list values are ints
    line[0] = int(line[0])
    if 1 < len(line) < 3:
        line[1] = int(line[1])
    else:
        for x in range(len(line)):
            line[x] = int(line[x])
        print("The coordinates you entered "
              + str(line)
              + " are not valid. Please enter again.")
        line = is_valid_coord(line, player)
    return line


def check_coordinates(player_lines, lines):
    """
    checks coordinates

    :param player_lines: player inputted lines
    :param lines: already made lines
    :return: returns true if coordinates already exist in lines
    """
    # since coordinates can be reverse and have to check both combinations
    coordinates_reversed = [player_lines[1], player_lines[0]]
    # if already in player_lines returns true
    if player_lines[0] > MAX or \
            player_lines[0] < MIN or player_lines[1] > MAX or \
            player_lines[1] < MIN:
        return True
    elif player_lines in lines or coordinates_reversed in lines \
            or player_lines[1] == player_lines[0]:
        return True
    else:
        return False


def is_valid_coord(list_lines, player):
    """
    Return the pair of lines if valid

    :param list_lines: ALREADY connected lines
    :param player: player number 1  or 2
    :returns: coordinates in form of [x,y]
    """
    # gets coordinates
    player_lines = get_coordinates(player)
    # if check_coordinates is true then re prompts
    while check_coordinates(player_lines, list_lines):
        print("The coordinates you entered "
              + str(player_lines)
              + " are not valid. Please enter again.")
        player_lines = get_coordinates(player)
    # else returns input coordinate list [a,b]
    return player_lines


def add_lines(player1_lines, player2_lines, player):
    """
    adds the lines to the respective lists

    :param player1_lines: player 1 lines
    :param player2_lines: player 2 lines
    :param player: player number
    :return: no return, just appends them to lists
    """
    if player == P1:
        # lines already chosen
        list_lines = player1_lines + player2_lines
        player1_lines.append(is_valid_coord(list_lines, P1))
    if player == P2:
        # lines already chosen
        list_lines = player2_lines + player1_lines
        player2_lines.append(is_valid_coord(list_lines, P2))


def check_triangle(list_lines):
    """
    make adjacency matrix
    3 for loops to check each vertices with edges
    because of 3 points there needs to be variables checked
    matrix[x][y] == 1 and matrix[x][y] == matrix[y][z] == matrix[z][x]
        return True
    else:
        because no triangle was detected
        return False
    """
    # 6x6 matrix with 0's representing no value
    adj_matrix = [[0, 0, 0, 0, 0, 0],
                  [0, 0, 0, 0, 0, 0],
                  [0, 0, 0, 0, 0, 0],
                  [0, 0, 0, 0, 0, 0],
                  [0, 0, 0, 0, 0, 0],
                  [0, 0, 0, 0, 0, 0]
                  ]

    for line in list_lines:
        """
        has to match index so value -1, takes the pair of coordinates and inputs
        them into matrix by indexes with value 1, and also inputs reverse
        coordinate to check if they are connected
        """
        adj_matrix[line[0] - 1][line[1] - 1] = 1
        adj_matrix[line[1] - 1][line[0] - 1] = 1
    # since triangle a,b,c in range 6 because 6x6 matrix
    for a in range(GRID):
        for b in range(GRID):
            for c in range(GRID):
                if adj_matrix[a][b] == 1 and \
                        adj_matrix[a][b] \
                        == adj_matrix[b][c] \
                        == adj_matrix[a][c]:
                    return True
    return False


def game_over(p1_lines, p2_lines):
    """
    checks if there is a triangle connection between points

    :returns: Boolean if there is a connection
    """
    # if there is a triangle returns True
    if check_triangle(p1_lines) or check_triangle(p2_lines):
        return True
    else:
        return False


def play():
    """
    Starts the game, while not game over it continues to ask users for input
    and appends them to corresponding lists and prints board every turn

    :Returns loser
    """
    # initiates player line lists
    player_one_lines = []
    player_two_lines = []
    # gets symbols
    p1_symbol = get_symbol(P1)
    p2_symbol = get_symbol(P2)
    # make sure that p2 symbol is not the same as p1 symbol
    while p2_symbol == p1_symbol:
        p2_symbol = get_symbol(P2)
    player_turn = P1
    # prints board for very first time
    print_board(player_one_lines, p1_symbol, player_two_lines, p2_symbol)
    # while not game over run
    while not game_over(player_one_lines, player_two_lines):
        if player_turn == P1:
            # gets and appends lines to respective lists
            add_lines(player_one_lines, player_two_lines, P1)
            # changes player turn
            player_turn = P2
        else:
            # gets and appends lines to respective lists
            add_lines(player_one_lines, player_two_lines, P2)
            # changes player turn
            player_turn = P1
        print_board(player_one_lines, p1_symbol, player_two_lines, p2_symbol)

    # after while loop finishes it checks who won
    if check_triangle(player_one_lines):
        return P1
    else:
        return P2


def won(player):
    """
    outputs statement respectively who won

    :param player: player number
    :return: nothing prints statements
    """
    if player == P1:
        print("Game over, Player 1 has lost")
    else:
        print("Game over, Player 2 has lost")


if __name__ == "__main__":
    # calls play which starts the game and play() will return a int 1 or 2
    # and will be inputted into won and won prints out who won
    won(play())