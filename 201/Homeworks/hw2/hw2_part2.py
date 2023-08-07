"""
File:    hw2_part2.py
Author:  Denish Pasupuleti
Date:    9/16/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  This program will provide mathematical commands for the use to choose
"""
if __name__ == '__main__':
    num = int(input("Enter an integer: "))
    command = input("Would you like to know if this number is "
                    "even,square it, or multiply it with another number? ")
    if command == "even":
        if num % 2 == 1:
            print('It is odd')
        else:
            print('It is even')
    elif command == "square":
        print(str(num**2))
    elif command == "multiply":
        other_num = int(input("What is the other number? "))
        print(str(num)
              + " times "
              + str(other_num)
              + " is "
              + str(num * other_num))
    else:
        print("I don't know what you're talking about.")