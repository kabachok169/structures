#!/usr/bin/env python

import matplotlib.pyplot as plt
import sys
import math


def average(vector):
    return float(sum(vector)) / len(vector)


def xy(x, y):
    s = []
    for i in range(len(x)):
        s.append(x[i]*y[i])
    return s

def very_bad_func(x, y):
    k = float(average(xy(x, y)) - average(x) * average(y)) / (average([xi ** 2 for xi in x]) - average(x) ** 2)
    b = average(y) - k * average(x)
    return (k, b)

def very_bad_func_log(x, y):
    lnx = [math.log(xi) for xi in x]
    k = float(average(xy(lnx, y)) - average(lnx) * average(y)) / (average([xi ** 2 for xi in lnx]) - average(lnx) ** 2)
    b = average(y) - k * average(lnx)
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
    strings.pop(len(strings) - 1)

    for string in strings:
        details = string.split(" ")
        if(details[0] == "push"):
            push_x.append(count)
            count += 1
            push_y.append(float(details[1]))
        elif(details[0] == "pop"):
            pop_x.append(count)
            if count:
                count -= 1
            pop_y.append(float(details[1]))
        elif (details[0] == "search"):
            search_x.append(count)
            search_y.append(float(details[1]))

    k1, b1 = very_bad_func(push_x, push_y)
    print k1, b1
    k2, b2 = very_bad_func(pop_x, pop_y)
    print k2, b2
    k3, b3 = very_bad_func_log(search_x, search_y)
    print k3, b3

    #print push_x

    new_dot_array1 = [k1 * x + b1 for x in push_x]
    new_dot_array2 = [k2 * x + b2 for x in pop_x]
    new_dot_array3 = [k3 * math.log(x) + b3 for x in search_x]

    new_dot_array1_1 = [2 * k1 * x + b1 for x in push_x]
    new_dot_array2_1 = [2 * k2 * x + b2 for x in pop_x]
    new_dot_array3_1 = [2 * k3 * x + b3 for x in search_x]


    # plt.plot(push_x, push_y, 'r')

    plt.figure(figsize=(30, 40))
    plt.subplot(221)
    plt.xlabel("count of objects")
    plt.ylabel("time")
    plt.title("Push")
    plt.scatter(push_x, push_y, edgecolors='r', s=5)
    plt.plot(push_x,new_dot_array1)
    plt.plot(push_x,new_dot_array1_1)
    # plt.show()

    # plt.plot(pop_x, pop_y, 'r')
    plt.subplot(222)
    plt.xlabel("count of objects")
    plt.ylabel("time")
    plt.title("Pop")
    plt.scatter(pop_x, pop_y, edgecolors='r', s=10)
    plt.plot(pop_x, new_dot_array2)
    plt.plot(pop_x,new_dot_array2_1)

    # plt.show()

    plt.subplot(223)
    plt.xlabel("count of objects")
    plt.ylabel("time")
    plt.title("Search")
    plt.scatter(search_x, search_y, edgecolors='r', s=10)
    plt.plot(search_x, new_dot_array3)
    # plt.plot(search_x, new_dot_array3_1)

    # plt.show()


    plt.show()
