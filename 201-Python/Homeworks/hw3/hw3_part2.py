"""
File:    hw3_part2.py
Author:  Denish Pasupuleti
Date:    9/16/19
Section: 34
E-mail:  mpasupu1@umbc.edu
Description:
  This program will output the smallest and largest number in the lis
  also the average of the list
"""
if __name__ == '__main__':
    numbers = [75, 635, 274, 353, 534, 684, 381, 67, 968, 155, 502, 149, 10, 789, 757, 379, 732, 386, 692, 473, 797,
               272, 538, 703, 629, 179, 197, 521, 411, 590, 818, 892, 896, 951, 365, 800, 767, 651, 584, 220, 584, 221,
               23, 819, 794, 957, 74, 985, 395, 544, 324, 464, 980, 293, 980, 208, 560, 651, 710, 21, 322, 968, 610,
               947, 622, 369, 504, 113, 785, 119, 46, 332, 137, 865, 127, 333, 83, 403, 696, 771, 733, 811, 220, 451,
               559, 446, 895, 90, 591, 257, 506, 208, 432, 197, 16, 344, 261, 830, 115, 924, 288, 442, 464, 213, 409,
               815, 495, 205, -123, 147, 930, 69, 188, 419, 880, 815, 291, 646, 464, 888, 310, 228, 529, 218, 565, 642,
               315, 328, 288, 374, 208, 830, 834, 879, 75, 983, 112, 556, 736, 211, 582, 437, 717, 833, 719, 684, 518,
               517, 744, 350]
    # Average
    sum_num = 0
    for y in numbers:
        sum_num += y
    average = float(sum_num / len(numbers))
    print("The average is: " + str(average))
    # Greatest in the list
    maximum = numbers[0]
    for i in numbers:
        if i > maximum:
            maximum = i
    print("The largest value is: " + str(maximum))
    # Smallest value in the list
    minimum = numbers[0]
    for x in numbers:
        if x < minimum:
            minimum = x
    print("The smallest value is: " + str(minimum))




