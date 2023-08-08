"""
File:    hw2_part4.py
Author:  Denish Pasupuleti
Date:    9/16/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  This program will output which day of September it is
"""
if __name__ == '__main__':
    day = int(input("What day of September 2019 are we in? "))
    if(day > 1) and (day < 31):
        if (day == 1) or ((day % 7) == 1):
            print("It's a sunday ")
        if(day == 2) or ((day % 7) == 2):
            print("It's a monday")
        elif (day == 3) or ((day % 7) == 3):
            print("It's a Tuesday")
        elif (day == 4) or ((day % 7) == 4):
            print("It's a Wednesday")
        elif (day == 5) or ((day % 7) == 5):
            print("It's a Thursday")
        elif (day == 6) or ((day % 7) == 6):
            print("It's a Friday")
        elif(day == 7) or ((day % 7) == 0):
            print("It's a Saturday")
    else:
        print("That's not a valid day.")
