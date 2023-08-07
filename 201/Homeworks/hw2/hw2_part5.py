"""
File:    hw2_part5.py
Author:  Denish Pasupuleti
Date:    9/16/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  This program will determine what genus type a plant is
"""
if __name__ == '__main__':
    eat_bugs = input("Does the plant eat bugs? ")
    if eat_bugs == "yes":
        trap_jaws = input("Does the plant use a pitfall trap or snap jaws? ")
        if trap_jaws == "pitfall trap":
            print("Oh, interesting. That is a Nepenthes. "
                  "Don't drink from a pitcher plant.")
        elif trap_jaws == "snap jaws":
            print("Watch those fingers! You got a "
                  "Dionaea muscipula: the venus fly trap")
        else:
            print("I don't know what that is...")
    elif eat_bugs == "no":
        petals = int(input("How many petals does this thing have? "))
        if petals == 3:
            multiple_flowers = input("Does it have multiple flowers? ")
            if multiple_flowers == "yes":
                print("I don't know what that is...")
            else:
                print("Irises are nice, and that's what you have.")
        if petals == 5:
            multiple_flowers = input("Does it have multiple flowers? ")
            if multiple_flowers == "yes":
                print("I don't know what that is...")
            else:
                print("Oh, you have an Orchidacea, "
                      "known by its friends as an orchid")
        if petals > 7:
            multiple_flowers = input("Does it have multiple flowers? ")
            if multiple_flowers == "yes":
                height = int(input("How many cm tall is it? "))
                if height > 300:
                    print("Oh, that is a Helianthus annuus, "
                          "or sunflower for the uninitiated")
                else:
                    print("Hmm, that is some kind of Asteracea. "
                          "Premium specimen of photosynthetic evolution!")