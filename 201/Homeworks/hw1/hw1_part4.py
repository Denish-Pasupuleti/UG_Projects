"""
File:    hw1_part4.py
Author:  Denish Pasupuleti
Date:    9/7/19
Section: 34
E-mail:  dennesspasupuleti@gmail.com
Description:
  This program will compute the total cost of
  annual inspection,fuel,hangar fees,propeller fluid
"""

annual_inspection = float(input('What was the cost of the annual inspections?' ))
fuel = float(input('What was the cost of the fuel?' ))
hangar_fees = float(input('What was the cost of the hangar fees?' ))
propeller_fluid = float(input('What was the cost of the propeller fluid?' ))
total_cost = (annual_inspection
              + fuel
              + hangar_fees
              + propeller_fluid
              )
print('The total annual cost of the aircraft is '
      + str(total_cost)
      )