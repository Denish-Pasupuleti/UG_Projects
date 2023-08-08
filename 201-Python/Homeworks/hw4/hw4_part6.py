"""
File:    hw4_part6.py
Author:  Denish Pasupuleti
Date:    9/29/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program will output a counting box
"""
if __name__ == "__main__":
    WIDTH = int(input("Enter a width: "))
    HEIGHT = int(input("Enter a height: "))
    counter = 0
    for column in range(HEIGHT):
        print()
        for row in range(WIDTH):
            print(str(counter), end=" ")
            counter += 1