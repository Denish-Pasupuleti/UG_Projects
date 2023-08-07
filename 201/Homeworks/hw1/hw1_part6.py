"""
File:    hw1_part6.py
Author:  Denish Pasupuleti
Date:    9/7/19
Section: 34
E-mail:  dennesspasupuleti@gmail.com
Description:
  This program will compute the total cost of the meal with tax and tip
"""

bill = float(input('How much was the bill? '))
tax = float(input('How much is tax in your area? '))
percentage_tip = float(input('What percentage do you want to tip?' ))
tip = float((bill * percentage_tip)/100)
total_cost = float(bill
                   + tip
                   + (bill * (tax/100))
                   )
print('The total cost of the meal will be '
      + str(total_cost)
      )

