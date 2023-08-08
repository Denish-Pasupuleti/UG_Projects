"""
File:    hw2_part3.py
Author:  Denish Pasupuleti
Date:    9/16/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  This program will decide which monster is powerful based on power level
"""
if __name__ == '__main__':
    monster_one = input("What is the name of the first monster? ")
    monster_one_plvl = int(input("What is the power level "
                                 "of the first monster? "))
    monster_two = input("What is the name of the second monster? ")
    monster_two_plvl = int(input("What is the power level "
                                 "of the second monster? "))
    if monster_one_plvl > monster_two_plvl:
        print(monster_one
              + " wins!")
    elif monster_one_plvl == monster_two_plvl:
        print("It's a draw")
    else:
        print(monster_two
              + " wins!")
    if(monster_one_plvl * 2) <= monster_two_plvl:
        print(monster_two
              + " was super efficacious!")
    elif(monster_two_plvl * 2) <= monster_one_plvl:
        print(monster_one
              + " was super efficacious!")
