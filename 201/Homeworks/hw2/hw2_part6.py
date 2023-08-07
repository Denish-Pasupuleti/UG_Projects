"""
File:    hw2_part6.py
Author:  Denish Pasupuleti
Date:    9/16/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  This program will open the door
  if only the first or the second lever is pulled
"""
if __name__ == '__main__':
    first_lever = input("Do you pull the first lever? ")
    second_lever = input("Do you pull the second lever? ")
    third_lever = input("Do you pull the third lever? ")
    if (first_lever == "yes" or third_lever == "yes") \
            and (second_lever == "no"):
        print("The door opens!")
    else:
        print("The door remains shut.")