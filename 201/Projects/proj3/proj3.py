"""
File:    proj3.py
Author:  Denish Pasupuleti
Date:    Dec 6 2019
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program will score a board from the board game go
the board is already provided and complete. It will recursively go through
each point and determine its owner either "X" or "O"
and replace the "+" accordingly
"""

# CONSTANTS
BLACK = "X"
WHITE = "O"
EMPTY = "+"
REST_ROW = 2


def get_board():
    """
    Gets the board by asking the user the name of the file
    :return:
    """
    file_name = input("What is the go board file name? ")
    file = open(file_name, "r")
    board = []
    for line in file:
        board.append(line.strip())
    file.close()
    return board


def row_fill(row, color):
    """
    This fills the row and just adds the color to the beginning of the list

    :param row: board[0] row
    :param color: first color the function finds
    :return: returns recursively rhe color to be added and the
    rest of the row so the color just gets added to the list
    """
    if len(row) == 1:
        return [color]
    if len(row) > 2:
        if row[0] == BLACK and row[1] == WHITE:
            color = [BLACK, WHITE]
            return color + row_fill(row[REST_ROW:], color[1])
        elif row[0] == WHITE and row[1] == BLACK:
            color = [WHITE, BLACK]
            return color + row_fill(row[REST_ROW:], color[1])
    return [color] + row_fill(row[1:], color)


def color_find(board):
    """
    Finds the first BLACK or WHITE in given row

    :param board: go board
    :return: the first color it finds
    """
    if len(board) == 0:
        return EMPTY
    for x in range(len(board)):
        for y in range(len(board[x])):
            if board[x][y] == BLACK:
                return BLACK
            elif board[x][y] == WHITE:
                return WHITE
    return color_find(board[1:])


def populate_board(board, color):
    """
    This function just adds filled rows together creating one list

    :param board: go board
    :param color: first BLACK or WHITE
    """
    if len(board) == 0:
        return []
    else:
        for x in range(len(board)):
            for y in range(len(board[x])):
                row = board[0]
                list.remove(board, board[0])
                filled_row = row_fill(row, color)
                return [filled_row] + populate_board(board, color)


def print_board(board):
    """
    Prints board

    :param board: go board
    :return: none, just prints out the char
    """
    for x in board:
        for y in x:
            print(y, end="")
        print("")


def score_board(board):
    """
    Function scores the board and adds 1 to respective counter

    :param board: painted go board
    :return: none, just prints out the score of each color
    """
    counter_x = 0
    counter_y = 0
    for x in range(len(board)):
        for y in range(len(board[x])):
            if board[x][y] == BLACK:
                counter_x += 1
            elif board[x][y] == WHITE:
                counter_y += 1
    print("BLACK score: " + str(counter_x))
    print("WHITE score: " + str(counter_y))


def score():
    """
    Sort of like a main but instead made into a function
    Makes it easier to manipulate and test cases.
    gets board, prints original board recursively paints board,
    prints painted board

    :return: none, prints respective statments
    """
    # get_board()
    go_board = get_board()
    print("Original board:")
    print_board(go_board)
    print("")
    print("Painted board")
    painted = populate_board(go_board, color_find(go_board))
    print_board(painted)
    print("")
    score_board(painted)


if __name__ == "__main__":
    # calls score which will initiate the program
    score()