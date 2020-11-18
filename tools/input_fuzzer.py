#! /usr/bin/python

import random


def invalid_ascii_input():

    input_string = ""
    
    for i in range(1,50):
        input_string += chr(random.randint(int(0x00), int(0x7E)))

    print(input_string)


def valid_input():

    input_string  = ""
    functions = ["sin" , "cos", "tan", "sqrt"]
    operators = ["+", "-", "*", "/", "^"]
    other_stuff = ["(", ")", "[", "]", "{", "}", " ", "\t", "\n"]
    
    available = functions + operators + other_stuff

    for i in range(1,10):
        token = random.randint(0,2)
        if token == 0:
            input_string += functions[random.randint(0, len(functions)-1)]
        if token == 1:
            input_string += operators[random.randint(0, len(operators)-1)]
        if token == 2:
            input_string += other_stuff[random.randint(0, len(other_stuff)-1)]
        else:
            input_string += str(random.uniform(0.0, 199.99999))

    print(input_string)


if __name__ == "__main__":
    valid_input()
