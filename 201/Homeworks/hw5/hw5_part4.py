"""
File:    hw5_part4.py
Author:  Denish Pasupuleti
Date:    10/9/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description: This program enlolinates a sentence
"""
if __name__ == "__main__":
    CONSONANTS = ["b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n",
                  "p", "q", "r", "s", "t", "v", "w", "x", "z"
                  ]
    sentence = input("Enter a sentence: ")
    temp = ""
    for i in range(len(sentence)-1):
        if sentence[i].lower() in CONSONANTS and sentence[i+1].lower() not in CONSONANTS:
            temp += sentence[i] + "ol"
        else:
            temp += sentence[i]
    end_index = (len(sentence)-1)
    if sentence[end_index].lower() in CONSONANTS:
        temp = temp + sentence[end_index] + "ol"
    print(temp)