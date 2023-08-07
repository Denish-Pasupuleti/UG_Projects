"""
File:    hw4_part3.py
Author:  Denish Pasupuleti
Date:    9/29/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program will store requests for clothing designs
"""
if __name__ == "__main__":
    STYLE = input("Hello customer! "
                  "What kind of design are you looking for? \n"
                  "Valid options are 'classy', 'playful', or 'business' ")
    STYLES = ["classy", "playful", "business"]
    # STYLE INPUT VERIFICATION
    print("")
    while STYLE not in STYLES:
        print(STYLE + " is not a valid style")
        STYLE = input("What kind of design are you looking for? \n"
                      "Valid options are 'classy', 'playful', or 'business'")
    print("")
    # HEIGHT INPUT VERIFICATION
    HEIGHT = float(input("What is your height in inches? "))
    while HEIGHT <= 0:
        HEIGHT = float(input("Height must be greater than 0. "
                             "What is your height? "))
    print("")
    # DATE INPUT VERIFICATION
    DATE = int(input("How many days from now do you need the design? \n"
                     "(Our minimum wait time is one week)"))
    while DATE < 7:
        DATE = int(input("Sorry, we need at least a week for the design. \n"
                         "Please enter how many days "
                         "from now you will need the design"))
    print("")
    print("Great, We will get to work on a "
          + STYLE
          + " design for a "
          + str(HEIGHT)
          + " inch tall human.\nIt will be ready in "
          + str(DATE)
          + " days or less.")