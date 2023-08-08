"""
File:    hw4_part2.py
Author:  Denish Pasupuleti
Date:    9/29/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program will calculate integer division
without using the division,integer division,mod, or multiplication
operators.
"""
if __name__ == "__main__":
    FIRST_NUM = int(input("Please enter the first number: "))
    SECOND_NUM = int(input("Please enter the second number: "))
    temp_num1 = FIRST_NUM
    temp_num2 = SECOND_NUM
    answer = 0
    while temp_num1 >= temp_num2:
        temp_num1 -= temp_num2
        answer += 1
    print(str(FIRST_NUM)
          + " // "
          + str(SECOND_NUM)
          + " = "
          + str(answer)
          )