"""
File:        errors.py
Author:      Dr. Gibson
Date:        9/8/2017
Lab Section: All
UMBC email:  k.gibson@umbc.edu
Description: This program contains buggy Python code 
             that needs to be fixed.
"""

if __name__ == "__main__":
    
    print("This program finds the average of three integers.")

    num1 = int(input("Enter the first  number please: "))
    num2 = int(input("Enter the second number please: "))
    num3 = int(input("Enter the third  number please: "))
    average = (num1 + num2 + num3) / 3

    print("The average of the three numbers is " + (str)( average))

