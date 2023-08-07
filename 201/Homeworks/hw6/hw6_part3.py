"""
File:    hw6_part3.py
Author:  Denish Pasupuleti
Date:    Nov 15, 2019
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  Replaces the hidden message in encrypted string with new hidden message
  even if the hidden message is spread out, it will replace the first
  occurrence of the character
"""


def replace_hidden_message(encrypted_message, hidden_message, new_hidden_message):
    """
    Replaces the hidden_message hidden in input_string
    with new_hidden_message
    :param encrypted_message: a message with something
    hidden in it
    :param hidden_message: the old hidden message
    :param new_hidden_message: the new hidden message
    that will replace it
    :return: encrypted_message where the first occurrence
    of hidden_message is replaced with new_hidden_message
    """
    new_string = ""
    if len(new_hidden_message) != len(hidden_message):
        return "The new message must be the same length.  Good day."
    if len(encrypted_message) != 0 and len(hidden_message) != 0:
        if encrypted_message[0] == hidden_message[0]:
            # adds first char in new hidden string
            new_string += new_hidden_message[0]
            return new_string + replace_hidden_message(encrypted_message[1:],
                                                       hidden_message[1:],
                                                       new_hidden_message[1:])
        else:
            # if not equal to hidden_string[0] adds encrypted[0]
            new_string += encrypted_message[0]
            return new_string + replace_hidden_message(encrypted_message[1:],
                                                       hidden_message,
                                                       new_hidden_message)
    else:
        return encrypted_message


if __name__ == "__main__":
    encrypted = input("Give me a string with a message hidden in it: ")
    hidden = input("Give me the hidden message: ")
    new_hidden = input("What do you want the new hidden message to be? ")
    print(replace_hidden_message(encrypted, hidden, new_hidden))
