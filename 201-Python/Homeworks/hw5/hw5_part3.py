"""
File:    hw5_part3.py
Author:  Denish Pasupuleti
Date:    10/9/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program draws a triangle with a symbol the user gives
"""
if __name__ == "__main__":
    height = int(input("What is the height of the triangle? "))
    width = height
    symbol = input("What is the symbol for the triangle? ")
    for x in range(0, height):
        for y in range(0, x+1):
            print(symbol, end="")
        print("\r")