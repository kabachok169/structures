#!/usr/bin/env python

import sys
import random

if __name__ == "__main__":

    filename = sys.argv[2]
    number = sys.argv[1]

    counter = 0
    pushed = []

    value1 = int(number) + 100

    for i in range(3):
        key = random.randint(0, 100000)
        value = random.randint(0, 5000)
        pushed.append((key, value))

    with open(filename, 'w') as file:
        file.write(number + "\n")
        for i in range(int(number)):

            command = random.randint(0, 20)

            if (command > 18):
                if counter >= 0:
                    file.write("pop {}\n".format(value1 + 1))
                    counter -= 1
                else:
                    command = random.randint(0, 16)
            else:
                if (command > 5):
                    key = value1
                    value = random.randint(0, 5000)
                    pushed.append((key, value))
                    file.write("push {} {}\n".format(key, value))
                    counter += 1
                    value1 -= 1
                else:
                    key, value = random.choice(pushed)
                    file.write("search {}\n".format(key))





        # file.write("print")




