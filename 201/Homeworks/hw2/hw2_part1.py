"""
File:    hw2_part1.py
Author:  Denish Pasupuleti
Date:    9/16/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  This program will help people decide what to put in their fish tank
"""
if __name__ == '__main__':
    fish_type = input("What type of fish would you like to purchase? ")
    if fish_type == "carnivorous":
        smaller_fish = input("Do you have smaller fish already? ")
        if smaller_fish == "no":
            print("Great! Enjoy!")
        else:
            print("This is a bad idea! It'll eat your little ones! ")
    elif fish_type == "salt water":
        print("Wow, you're a fancy fish parent!")
    elif fish_type == "community":
        already_have = int(input("How many fish of this "
                                 "species do you already have?"))
        if already_have < 3:
            print("You should get more than one!")
        else:
            print("Yay, more friends!")
    else:
        print("I don't think that's a type of fish. "
              "Maybe you're looking for a lizard?")



