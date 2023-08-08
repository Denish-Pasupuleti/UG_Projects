"""
File: major.py
Author: Denish Pasupuleti
Date: 09/19/19
Section: 34
E-mail: mpasupu1@umbc.edu
Description: This program will tell what grade
             they must receive for that major
"""
major = input("Please enter your major ")
if major == "CMSC" or major == "CMPE":
    print("You need to earn at least a B for CMSC 201 to count")
else:
    print("You need to earn at least a C for CMSC 201 to count")
    
