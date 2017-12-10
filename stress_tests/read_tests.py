import matplotlib.pyplot as plt
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
        elif (details[0] == "search"):
            search_x.append(count)
            search_y.append(details[1])

    k1, b1 = very_bad_func(push_x, push_y)
    k2, b2 = very_bad_func(push_x, push_y)
    k3, b3 = very_bad_func(push_x, push_y)

    new_dot_array1 = [k1*x + b1 for x in push_x]
    new_dot_array2 = [k2*x + b2 for x in pop_x]
    new_dot_array3 = [k3*x + b3 for x in search_x]


    # plt.plot(push_x, push_y, 'r')
    plt.subplot(221)
    plt.xlabel("count of objects")
    plt.ylabel("time")
    plt.title("Push")
    plt.scatter(push_x, push_y, edgecolors='r', s=5)
    plt.plot(new_dot_array1)
    # plt.show()

    # plt.plot(pop_x, pop_y, 'r')
    plt.subplot(222)
    plt.xlabel("count of objects")
    plt.ylabel("time")
    plt.title("Pop")
    plt.scatter(pop_x, pop_y, edgecolors='r', s=10)
    plt.plot(new_dot_array2)
    # plt.show()

    plt.subplot(223)
    plt.xlabel("count of objects")
    plt.ylabel("time")
    plt.title("Search")
    plt.scatter(search_x, search_y, edgecolors='r', s=10)
    plt.plot(new_dot_array3)
    # plt.show()

    plt.show()

