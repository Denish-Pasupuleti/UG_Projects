"""
File:    hw1_part2.py
Author:  Denish Pasupuleti
Date:    9/7/19
Section: 34
E-mail:  dennesspasupuleti@gmail.com
Description:
  This program will compute the amount of candy bars earned today
  by using the user's daily income and each candy bar cost
"""

daily_income = float(input('What is your daily income' ))
candybar_cost = float(input('How much does your favorite candy bar cost?' ))
earned = float(daily_income/candybar_cost)
print('you earned '
      + str(earned)
      + ' candy bars today!'
      )




