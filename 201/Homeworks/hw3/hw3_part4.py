"""
File:    hw3_part4.py
Author:  Denish Pasupuleti
Date:    9/16/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  This program will ask the user for 3 animals and 3 clothing items
  and output each animal wearing each clothing item
"""
if __name__ == '__main__':
    list_names = [input("What is the first animal? "),
                  input("What is the second animal? "),
                  input("What is the third animal? "),
                  ]
    list_clothing = [input("What is the first piece of clothing "),
                     input("What is the second piece of clothing? "),
                     input("What is the third piece of clothing? "),
                     ]
    for names in list_names:
        for clothing in list_clothing:
            print(names + " is wearing a " + clothing + " -- crazy!")