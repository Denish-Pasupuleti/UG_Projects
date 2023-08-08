"""
File:    proj1.py
Author:  Denish Pasupuleti
Date:    10/15/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
         You are implementing an exciting new baking sim!
         First players will go to the grocery store and purchase ingredients
         for baking baguettes, macarons, and croissants.
         If they fail to stay within their budget or
         fail to purchase enough ingredients, they LOSE!

         If they are successful at purchasing ingredients,
         then they are then returned to the kitchen where they chose what items to work on.
         They must begin the baguette dough before working on the macarons and croissants,
         and they must finish every other task before baking the baguettes.
"""

STARTING_FUNDS = 80.0

# costs for ingredients
FLOUR_COST_PER_BAG = 2.5
EGGS_COST_PER_CRATE = 1.9
YEAST_COST_PER_BAG = 3.25
BUTTER_COST_PER_PACK = 1.25
MILK_COST_PER_JUG = 2.75

# ingredients per x
GALLONS_MILK_PER_JUG = 1.0
EGGS_PER_CRATE = 24.0
TBSP_BUTTER_PER_PACK = 64.0
CUPS_FLOUR_PER_BAG = 25.0
CUP_YEAST_PER_BAG = 6.0

# required ingredients
EGGS_REQUIRED = 12.0 + 60.0
FLOUR_REQUIRED = 48.0 + 112.5
BUTTER_REQUIRED = 144.0
YEAST_REQUIRED = 39 + 50
MILK_REQUIRED = 18.0

# measurements
CUPS_IN_GALLON = 16
TSP_IN_CUP = 48


def go_shopping():
    """
    go shopping function is the very beginning of the program where the user
    will be asked to buy x ingredient and y amount of it.If the user still
    has money the program will continue else it will output that they ran
    out of money
    :return: shopping cart if user did not run out of money
    """
    money = STARTING_FUNDS
    # shopping cart where purchased amounts will be placed
    shopping_cart = ["eggs", 0, "flour", 0, "butter", 0, "yeast", 0, "milk", 0]
    # each purchased ingredient amount gets its own variable
    amount_eggs = 0.0
    amount_flour = 0.0
    amount_butter = 0.0
    amount_yeast = 0.0
    amount_milk = 0.0
    # SENTINEL
    SENTINEL = "NOTHING"
    option = ""
    print("Welcome to the supermarket! ")
    while option != SENTINEL:
        if money <= 0:
            print("You have run out of money")
            return shopping_cart
        else:
            option = input("What would you like to purchase? (ENTER 'NOTHING' to leave store) ")
            # checks SENTINEL
            if option == SENTINEL:
                return shopping_cart
            # EGG
            elif option == "eggs":
                eggs = int(input("How many crates of eggs would you like? "))
                amount_eggs = float(eggs * EGGS_PER_CRATE)
                money -= eggs * EGGS_COST_PER_CRATE
                if amount_eggs > 0:
                    del shopping_cart[1]
                    shopping_cart.insert(1, amount_eggs)
            # FLOUR
            elif option == "flour":
                flour = int(input("How many bags of flower would you like? "))
                amount_flour = float(flour * CUPS_FLOUR_PER_BAG)
                money -= flour * FLOUR_COST_PER_BAG
                if amount_flour > 0:
                    del shopping_cart[3]
                    shopping_cart.insert(3, amount_flour)
            # BUTTER
            elif option == "butter":
                butter = int(input("How many packs of butter would you like? "))
                amount_butter = float(butter * TBSP_BUTTER_PER_PACK)
                money -= butter * BUTTER_COST_PER_PACK
                if amount_butter > 0:
                    del shopping_cart[5]
                    shopping_cart.insert(5, amount_butter)
            # YEAST
            elif option == "yeast":
                yeast = int(input("How many bags of yeast would you like? "))
                amount_yeast = float(yeast * CUP_YEAST_PER_BAG)
                amount_yeast = float(amount_yeast * TSP_IN_CUP)
                money -= yeast * YEAST_COST_PER_BAG
                if amount_yeast > 0:
                    del shopping_cart[7]
                    shopping_cart.insert(7, amount_yeast)
            # MILK
            elif option == "milk":
                milk = int(input("How many jugs of milk would you like? "))
                amount_milk = float((milk * GALLONS_MILK_PER_JUG) * CUPS_IN_GALLON)
                money -= milk * MILK_COST_PER_JUG
                if amount_milk > 0:
                    del shopping_cart[9]
                    shopping_cart.insert(9, amount_milk)
            # if the user input does not match any options
            elif option != "eggs" and option != "flour" and \
                    option != "butter" and option != "yeast" and option != "milk":
                print("That is not a valid entry ")


def check_items_enough(shopping_cart):
    """
    check_items_enough(shopping_canrt) function is for checking that
    every ingredient in the cart has sufficient amounts to start baking
    :param shopping_cart:
    :return: FALSE if there aren't enough ingredients (SEE REQUIRED INGREDIENT AMOUNTS)
    """
    requirements_met = False
    # each ingredient is tested separately
    eggs_met = False
    flour_met = False
    butter_met = False
    yeast_met = False
    milk_met = False
    # for eggs
    if float(shopping_cart[1]) >= EGGS_REQUIRED:
        eggs_met = True
    else:
        required = EGGS_REQUIRED - float(shopping_cart[1])
        print("You didn't buy enough eggs! We needed: "
              + str(required) + " more cups")
    # for flour
    if float(shopping_cart[3]) >= FLOUR_REQUIRED:
        flour_met = True
    else:
        required = float(FLOUR_REQUIRED - shopping_cart[3])
        print("You didn't buy enough flour! We needed: "
              + str(required) + " more cups")
    # for butter
    if float(shopping_cart[5]) >= BUTTER_REQUIRED:
        butter_met = True
    else:
        required = float(BUTTER_REQUIRED - shopping_cart[5])
        print("You didn't buy enough butter! We needed: "
              + str(required) + " more tbsp")
    # for yeast
    if float(shopping_cart[7]) >= YEAST_REQUIRED:
        yeast_met = True
    else:
        required = float(YEAST_REQUIRED - shopping_cart[7])
        print("You didn't buy enough yeast! We needed: "
              + str(required) + " more tsp")
    # for milk
    if float(shopping_cart[9]) >= MILK_REQUIRED:
        milk_met = True
    else:
        required = float(MILK_REQUIRED - shopping_cart[9])
        print("You didn't buy enough milk! We needed: "
              + str(required) + " more cups")
    # if all requirements met
    if eggs_met and flour_met and butter_met and yeast_met and milk_met is True:
        requirements_met = True
    # if not program returns False
    else:
        print("You did not buy enough ingredients to even begin baking.\n"
              "You are a failure of all sorts. Good day")
        requirements_met = False
    return requirements_met


def print_task_list(tasks):
    """
    print_task_list(tasks_remaining) function just prints out
    each task that is remaining
    :param tasks:
    :return:
    """
    counter = 1
    print("Here are your remaining tasks of the day")
    for task in tasks:
        print(str(counter) + " - " + task)
        counter += 1


def is_valid_input(index, tasks):
    """
    This function will return True or False
    if the index is within the given constraint
    :param index:
    :param tasks:
    :return: True if index is within 0 and tasks length
             which will vary
    """
    if 0 <= index < len(tasks):
        return True
    else:
        return False


def bake():
    # task remaining list
    tasks_remaining = ["Begin the baguette dough",
                       "Make the macarons",
                       "make the croissants",
                       "bake the baguettes"
                       ]
    # appropriate responses for each task
    responses = ["Ok, let's knead some baguette dough!",
                 "Adorable sandwich cookies coming right up! ",
                 "Let's make some flaky crescent goodness!",
                 "All done! Let's hope we've PRUEven ourselves"
                 ]
    # will check if we have enough ingredients
    # and starts the baking process
    if check_items_enough(go_shopping()):
        print("We have everything we need! Ready! Set! Bake! ")
        # while we have at least 1 task
        while len(tasks_remaining) != 0:
            print_task_list(tasks_remaining)
            # user input of index
            action = int(input("What action would you like to "
                               "cross off your list next? "))
            # checks if this the beginning
            if "Begin the baguette dough" in tasks_remaining[0]:
                if action == 1:
                    print(responses[action-1])
                    list.remove(tasks_remaining, tasks_remaining[0])
                    list.remove(responses, responses[0])
                # if other than 1
                elif is_valid_input(action-1, tasks_remaining):
                    print("We should really start the baguette dough first!")
            # other than 1 checks for valid input
            # and if bake baguette is still in list then proceeds to
            # do the task ex. 2 for macarons or croissants
            else:
                if (is_valid_input(action-1, tasks_remaining) and
                    "bake the baguettes" not in tasks_remaining[action - 1]) or \
                        len(tasks_remaining) == 1:
                    print(tasks_remaining[action-1])
                    print(responses[action-1])
                    list.remove(tasks_remaining, tasks_remaining[action-1])
                    list.remove(responses, responses[action-1])
                else:
                    print("Whoa, we should probably do everything else first!")


if __name__ == "__main__":
    print("Baker!  You must buy the following with $" + str(STARTING_FUNDS ) + ": ")
    print()
    print("For 300 Croissants:"
          "\n\t48 cups of flour "
          "\n\t12 eggs "
          "\n\t144 tbsp of butter "
          "\n\t39 tsp of yeast"
          "\n\t18 cups of milk\n"
          )
    print("For 600 macarons: \n"
          "\t60 eggs")
    print("For 100 baguettes: \n"
          "\t112.5 cups of flour\n"
          "\t50 tsp of yeast")
    print()
    # calls bake which will trigger the initial process
    bake()
