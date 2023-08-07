if __name__ == "__main__":
    """                                                                             
    File:         FILENAME.py                                                       
    Author:       YOUR NAME                                                         
    Date:         10/TODAY/2019                                                     
    Section:      YOUR SECTION NUMBER                                               
    E-mail:       USERNAME@umbc.edu                                                 
    Description:  YOUR DESCRIPTION GOES HERE AND HERE                               
                  YOUR DESCRIPTION CONTINUED SOME MORE                              
    """


    def sum_list(numbers):
        """
        Sums a list of integers
        :param numbers: a list of integers
        :return: the sum of the integers in numbers
        """
        sum = 0
        for x in numbers:
            sum += x
        return sum

    def get_string_lengths(strings):
        """
        Given a list of strings, return a list of integers representing
        the lengths of the input strings
        :param strings: a list of strings
        :return: a list of integers representing the lengths of the input strings
        """
        length = 0
        for string in strings:
            length += len(string)
        return "There are " + str(length) + " letters in the names you entered."

    def get_names():
        """
        Asks the user for a list of names
        :return: a list of strings for the names the user entered
        """
        names = []
        SENTINEL = False
        while SENTINEL == False:
            name = input("Enter a name, STOP to stop")
            if name == "STOP" or name == "stop":
                SENTINEL = True
            else:
                names.append(name)
        return names

    if __name__ == '__main__':
        kitties = [
            "Jules",
            "Stubby",
            "Tybalt",
            "Scooter",
            "KC",
            "Garfield",
            "Bucky"
    ]

    print(get_string_lengths(kitties))
    # print the sum of the lengths of the strings in kitties

    puppers = [
        "Charlie",
        "Chuck",
        "Chuckadero",
        "Char",
        "Charmander",
        "Charles, Lord of Hearts, King of Snuggles"
    ]
    print(get_string_lengths(puppers))

    # prints the sum of the lengths of the strings in puppers

    # gets names from the user and reports how many letters are in all the name\
    print(get_string_lengths(get_names()))


