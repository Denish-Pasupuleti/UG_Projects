"""
File:    hw5_part1.py
Author:  Denish Pasupuleti
Date:    10/9/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program weaves two strings together
"""
if __name__ == "__main__":
    word_list = []
    other_word_list = []
    TERMINATE = False
    # first list
    while not TERMINATE:
        words = input("Enter words, STOP to stop ")
        if words == "STOP":
            TERMINATE = True
        else:
            word_list.append(words)
    print("Ok. Now enter " + str(len(word_list)) + " other words")
    # second list
    for x in range(0, len(word_list)):
        other_word = input("Word " + str(x) + ":")
        other_word_list.append(other_word)
    # printing
    print("Now I will magically weave them!")
    for word in range(0, len(word_list)):
        print(word_list[word])
        print(other_word_list[word])

