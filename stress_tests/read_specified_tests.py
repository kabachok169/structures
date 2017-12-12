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
    count_list = 0
    count_array = 0
    count_elist = 0

    push_list_x = []
    push_list_y = []

    pop_list_x = []
    pop_list_y = []

    search_list_x = []
    search_list_y = []

    push_array_x = []
    push_array_y = []

    pop_array_x = []
    pop_array_y = []

    search_array_x = []
    search_array_y = []

    push_elist_x = []
    push_elist_y = []

    pop_elist_x = []
    pop_elist_y = []

    search_elist_x = []
    search_elist_y = []

    strings = my_file.read().split('\n')
    strings.pop(len(strings) - 1)

    k = 0

    for string in strings:
        details = string.split(" ")
        if details[0] == "push":
            if k % 3 == 0:
                push_list_x.append(count_list)
                count_list += 1
                push_list_y.append(float(details[1]))
            elif k % 3 == 1:
                push_array_x.append(count_array)
                count_array += 1
                push_array_y.append(float(details[1]))
            elif k % 3 == 2:
                push_elist_x.append(count_elist)
                count_elist += 1
                push_elist_y.append(float(details[1]))
        elif details[0] == "pop" :
            if k % 3 == 0:
                pop_list_x.append(count_list)
                if count_list > 0:
                    count_list -= 1
                pop_list_y.append(float(details[1]))
            elif k % 3 == 1:
                pop_array_x.append(count_array)
                if count_array > 0:
                    count_array -= 1
                pop_array_y.append(float(details[1]))
            elif k % 3 == 2:
                pop_elist_x.append(count_elist)
                if count_elist > 0:
                    count_elist -= 1
                pop_elist_y.append(float(details[1]))
        elif details[0] == "search" :
            if k % 3 == 0:
                search_list_x.append(count_list)
                search_list_y.append(float(details[1]))
            elif k % 3 == 1:
                search_array_x.append(count_array)
                search_array_y.append(float(details[1]))
            elif k % 3 == 2:
                search_elist_x.append(count_elist)
                search_elist_y.append(float(details[1]))
        k += 1

    # # print push_list_x
    # print push_list_y
    #
    # # print push_array_x
    # print push_array_y
    #
    # # print push_elist_x
    # print push_elist_y
    #
    # # print push_list_x
    # print pop_list_y
    #
    # # print push_array_x
    # print pop_array_y
    #
    # # print push_elist_x
    # print pop_elist_y
    #
    # # print push_list_x
    # print search_list_y
    #
    # # print push_array_x
    # print search_array_y
    #
    # # print push_elist_x
    # print search_elist_y


    k1, b1 = very_bad_func(push_list_x, push_list_y)
    # print k1, b1
    k2, b2 = very_bad_func(pop_list_x, pop_list_y)
    # print k2, b2
    k3, b3 = very_bad_func(search_list_x, search_list_y)

    k11, b11 = very_bad_func(push_array_x, push_array_y)
    # print k1, b1
    k22, b22 = very_bad_func(pop_array_x, pop_array_y)
    # print k2, b2
    k33, b33 = very_bad_func_log(search_array_x, search_array_y)

    k111, b111 = very_bad_func(push_elist_x, push_elist_y)
    # print k1, b1
    k222, b222 = very_bad_func(pop_elist_x, pop_elist_y)
    # print k2, b2
    k333, b333 = very_bad_func(search_elist_x, search_elist_y)
    # print k3, b3

    #print push_x

    new_dot_array1 = [k1 * x + b1 for x in push_list_x]
    new_dot_array2 = [k2 * x + b2 for x in pop_list_x]
    new_dot_array3 = [k3 * x + b3 for x in search_list_x]

    new_dot_array11 = [k11 * x + b11 for x in push_array_x]
    new_dot_array22 = [k22 * x + b22 for x in pop_array_x]
    new_dot_array33 = [k33 * math.log(x) + b33 for x in search_array_x]

    new_dot_array111 = [k111 * x + b111 for x in push_elist_x]
    new_dot_array222 = [k222 * x + b222 for x in pop_elist_x]
    new_dot_array333 = [k333 * x + b333 for x in search_elist_x]

    # plt.plot(push_x, push_y, 'r')

    plt.figure(figsize=(30, 40))
    plt.subplot(221)
    plt.xlabel("count of objects")
    plt.ylabel("time")
    plt.title("Push")
    # plt.scatter(push_x, push_y, edgecolors='r', s=5)
    plt.plot(push_list_x, new_dot_array1)
    plt.plot(push_array_x, new_dot_array11)
    plt.plot(push_elist_x, new_dot_array111)
    # plt.plot(push_x,new_dot_array1_1)
    # plt.show()

    # plt.plot(pop_x, pop_y, 'r')
    plt.subplot(222)
    plt.xlabel("count of objects")
    plt.ylabel("time")
    plt.title("Pop")
    # plt.scatter(pop_x, pop_y, edgecolors='r', s=10)
    plt.plot(pop_list_x, new_dot_array2)
    plt.plot(pop_array_x, new_dot_array22)
    plt.plot(pop_elist_x, new_dot_array222)
    # plt.plot(pop_x,new_dot_array2_1)

    # plt.show()

    plt.subplot(223)
    plt.xlabel("count of objects")
    plt.ylabel("time")
    plt.title("Search")
    # plt.scatter(search_x, search_y, edgecolors='r', s=10)
    plt.plot(search_list_x, new_dot_array3)
    plt.plot(search_array_x, new_dot_array33)
    plt.plot(search_elist_x, new_dot_array333)
    # plt.plot(search_x, new_dot_array3_1)

    # plt.show()


    plt.show()


