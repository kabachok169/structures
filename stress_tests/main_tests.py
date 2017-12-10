#!/usr/bin/env python

import sys
import random

if __name__ == "__main__":

    filename = sys.argv[2]
    number = sys.argv[1]
    structure = sys.argv[3]

    counter = 0
    pushed = []

    for i in range(int(number) / 10):
        key = random.randint(0, 10000)
        value = random.randint(0, 5000)
        pushed.append((key, value))

    with open(filename, 'w') as file:
        file.write(structure + "\n")
        file.write(number + "\n")
        for i in range(int(number)):

            command = random.randint(0, 2)

            if (command == 2):
                if counter >= 0:
                    key, value = random.choice(pushed)
                    file.write("pop {} {}\n".format(key, value))
                    counter -= 1
                else:
                    command = random.randint(0, 1)
            if (command == 0):
                key = random.randint(0, 10000)
                value = random.randint(0, 5000)
                pushed.append((key, value))
                file.write("push {} {}\n".format(key, value))
                counter += 1
            if (command == 1):
                key, value = random.choice(pushed)
                file.write("search {} {}\n".format(key, value))



