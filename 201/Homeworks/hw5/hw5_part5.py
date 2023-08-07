"""
File:    hw5_part5.py
Author:  Denish Pasupuleti
Date:    10/9/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program will print the words in reverse order
"""
if __name__ == "__main__":
    num_words = int(input("How many words would you like to turn backwards? "))
    words = []
    words_reversed = []
    # asking for words
    for i in range(1, num_words+1):
        words.append(input("Please enter a string #" + str(i) + ": "))
    # reverses the list
    for i in range(1, len(words) + 1):
        words_reversed.append(words[-i])
    # reversing the word
    for word in words_reversed:
        reversed_string = ""
        index = len(word)
        while index > 0:
            reversed_string += word[index - 1]
            index = index - 1
        print("The string " + "'" + str(word) + "' reversed is " + "'" + reversed_string + "'")

