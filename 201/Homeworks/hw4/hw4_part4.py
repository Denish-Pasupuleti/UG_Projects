"""
File:    hw4_part4.py
Author:  Denish Pasupuleti
Date:    9/29/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program will record mushroom sizes
and at the end categorizes them in large,small,and medium sizes
"""
if __name__ == "__main__":
    terminate = False
    large = 0
    small = 0
    medium = 0
    mushroom_weights = []
    weight = input("Enter a mushroom weight, or STOP to end.")
    while terminate == False:
        if weight == "STOP":
            terminate = True
        elif int(weight) <= 0:
            print("Weights must be greater than zero! ")
            weight = int(input("Enter a mushroom weight, or STOP to end."))
        else:
            mushroom_weights.append(int(weight))
            weight = (input("Enter a mushroom weight, or STOP to end."))
    for num in mushroom_weights:
        if num > 1000:
            large += 1
        if num < 100:
            small += 1
        if 100 < num < 1000:
            medium += 1
    print("The weights you entered were: " + str(mushroom_weights))
    print("There were "
          + str(small)
          + " small mushrooms,"
          + str(medium)
          + " mediums and "
          + str(large)
          + " larges")
