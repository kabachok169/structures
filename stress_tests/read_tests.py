import matplotlib.pyplot as plt
import subprocess
import random
import sys


def average(vector):
    return sum(vector) / len(vector)


def very_bad_func(x, y):
    k = (average([xi * yi for xi in x for yi in y]) - average(x) * average(y)) / (average([xi ** 2 for xi in x]) - average(x) ** 2)
    b = average(y) - k * average(x)
    return (k, b)

if __name__ == "__main__":

    my_file = open(sys.argv[1], "r")
    count = 0

    push_x = []
    push_y = []

    pop_x = []
    pop_y = []

    search_x = []
    search_y = []

    strings = my_file.read().split('\n')
    strings.erase(len(strings) - 1) # удаляем пустую строку

    for string in strings:
        details = string.split(" ")
        if(details[0] == "push"):
            push_x.append(count)
            count += 1
            push_y.append(details[1])
        elif(details[0] == "pop"):
            pop_x.append(count)
            count -= 1
            pop_y.append(details[1])
        elif (details[0] == "pop"):
            search_x.append(count)
            search_y.append(details[1])

    k1, b1 = very_bad_func(push_x, push_y)
    k2, b2 = very_bad_func(push_x, push_y)
    k3, b3 = very_bad_func(push_x, push_y)

    new_dot_array1 = []
    new_dot_array2 = []
    new_dot_array3 = []

    for x in push_x:
        

