"""
File:    hw6_part2.py
Author:  Denish Pasupuleti
Date:    Nov 15, 2019
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  Weaves two lists into one
"""


def zip_lists(list_one, list_two):
    """
    Creates a new list that alternates the values in list one and two.  The
    two lists must be of the same length.
    :param list_one: a list of values
    :param list_two: a list of values
    :return: a new list where list_one and list_two values alternate
    """
    new_list = []
    if len(list_one) == 0 and len(list_two) == 0:
        return new_list
    else:
        new_list.append(list_one[0])
        new_list.append(list_two[0])
        list.remove(list_one, list_one[0])
        list.remove(list_two, list_two[0])
        return new_list + zip_lists(list_one, list_two)


if __name__ == "__main__":
    list_one = []
    list_two = []
    word = input("Enter words, STOP to stop. ")
    while word != "STOP":
        list_one.append(word)
        word = input("Enter words, STOP to stop. ")
    print("Ok, Now enter " + str(len(list_one)) + " other words.")
    for num in range(len(list_one)):
        list_two.append(input("Word " + str(num) + ": "))
    print(zip_lists(list_one, list_two))