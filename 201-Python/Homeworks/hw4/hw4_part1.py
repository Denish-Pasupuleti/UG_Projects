"""
File:    hw4_part1.py
Author:  Denish Pasupuleti
Date:    9/29/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program simulates
the up and down movement of a hailstone in a storm
"""
if __name__ == "__main__":
    HAILSTONE = int(input("Please enter the "
                          "starting height of the hailstone: "))
    print("Hailstone is currently at height " + str(HAILSTONE))
    while HAILSTONE != 1 and HAILSTONE != 0:
        if int(HAILSTONE % 2) == 0:
            HAILSTONE = int(HAILSTONE / 2)
            print("Hailstone is currently at height " + str(HAILSTONE))
        elif int(HAILSTONE % 2) == 1:
            HAILSTONE = int((HAILSTONE * 3) +1)
            print("Hailstone is currently at height " + str(HAILSTONE))
    print("Hailstone stopped at height " + str(HAILSTONE))