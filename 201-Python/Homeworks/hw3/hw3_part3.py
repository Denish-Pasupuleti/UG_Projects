"""
File:    hw3_part3.py
Author:  Denish Pasupuleti
Date:    9/16/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  This program will ask for 5 names and various questions and
  depend on which names are given the others will be used
  to output something else
"""
if __name__ == '__main__':
    list_names = [input("Who is the first person? "),
                  input("Who is the second person? "),
                  input("Who is the third person? "),
                  input("Who is the fourth person? "),
                  input("Who is the fifth person? ")
                  ]
    SENTINEL = "no"  # sentinel to quit
    # Last piece of candy
    if SENTINEL == "no":
        last_candy = input("Which of these people would "
                           "you give your last piece of candy? ")
        if last_candy in list_names:
            list_names.remove(last_candy)
        else:
            SENTINEL = "yes"
    # road trip
    if SENTINEL == "no":
        road_trip = input("With which of these people "
                          "would you go on a 12 hour road trip? ")
        if road_trip in list_names:
            list_names.remove(road_trip)
        else:
            SENTINEL = "yes"
    # yacht tennis
    if SENTINEL == "no":
        yacht_tennis = input("With which of these people "
                             "would you play tennis on a yacht? ")
        if yacht_tennis in list_names:
            list_names.remove(yacht_tennis)
        else:
            SENTINEL = "yes"
    # cheat statement if SENTINEL = yes
    if SENTINEL == "yes":
        print("Hey, I don't know who that is! That's cheating!")
    # expected output when SENTINEL = no
    if SENTINEL == "no":
        print("I feel bad for these people: ")
        for x in list_names:
            print(x)

