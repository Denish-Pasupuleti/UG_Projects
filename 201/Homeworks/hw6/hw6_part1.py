"""
File:    hw6_part1.py
Author:  Denish Pasupuleti
Date:    Nov 15, 2019
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  does integer division recursively
"""


def integer_division(num1, num2):
    """
    Performs integer divison
    :param num1: Integer 1
    :param num2: Integer 2
    :return: returns how many times a number can be divided by integers
    """
    if num1 < num2:
        return 0
    else:
        return 1 + integer_division(num1-num2, num2)


if __name__ == "__main__":
    a = int(input("Enter a number: "))
    b = int(input("Enter another number: "))
    print("Integer division: ", integer_division(a, b))