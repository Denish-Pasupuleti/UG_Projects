"""
File:    hw4_part5.py
Author:  Denish Pasupuleti
Date:    9/29/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program will print the numbers from 1 up to a value
supplied by the user
"""
if __name__ == "__main__":
    start = 1
    upper_limit = int(input("What is the upper limit? "))
    for i in range(start, upper_limit):
        if i % 3 == 0 and i % 4 == 0:
            print("This is a very special time, savor it.")
        elif i % 3 == 0 and i % 4 != 0:
            print("One time I saw three hawks piled on a cactus")
        elif i % 4 == 0 and i % 3 != 0:
            print("Four, What is it good for? Absolutely nothing!")
        else:
            print(i)