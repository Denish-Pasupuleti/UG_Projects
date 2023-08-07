"""
File:    hw3_part1.py
Author:  Denish Pasupuleti
Date:    9/16/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  This program will ask if cheddar cheese is acceptable
  and output appropriate messages based on input
"""
if __name__ == '__main__':
    like_cheese = input("Do you like cheese? ")
    if like_cheese == "yes" or like_cheese == "Yes":
        cheddar_ok = input("Is cheddar ok? ")
        if cheddar_ok == "yes" or cheddar_ok == "Yes":
            print("Very well, here you are.")
        elif cheddar_ok == "no" or cheddar_ok == "No":
            print("Oh,then I suppose we will locate "
                  "another reasonably cheesy comestible.")
        else:
            print("I don't know what you're talking about.")
    elif like_cheese == "no" or like_cheese == "No":
        print("Well, I don't know what you're doing in a cheese shop then.")
    else:
        print("I don't know what you're talking about.")
