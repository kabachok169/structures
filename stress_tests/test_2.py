#!/usr/bin/env python

import sys
import random

if __name__ == "__main__":

    filename = sys.argv[2]
    number = sys.argv[1]

    counter = 0
    pushed = []

    for i in range(int(number) / 10):
        key = random.randint(0, 100000)
        value = random.randint(0, 5000)
        pushed.append((key, value))

    with open(filename, 'w') as file:
        file.write(number + "\n")
        for i in range(int(number) / 4):

            command = random.randint(0, 20)

            if (command > 18):
                if counter >= 0:
                    key, value = random.choice(pushed)
                    file.write("pop {}\n".format(key))
                    counter -= 1
                else:
                    command = random.randint(0, 16)
            else:
                if (command > 5):
                    key = random.randint(7000, 10000)
                    value = random.randint(0, 5000)
                    pushed.append((key, value))
                    file.write("push {} {}\n".format(key, value))
                    counter += 1
                else:
                    key, value = random.choice(pushed)
                    file.write("search {}\n".format(key))


        for i in range(int(number) / 4):

            command = random.randint(0, 20)

            if (command > 18):
                if counter >= 0:
                    key, value = random.choice(pushed)
                    file.write("pop {}\n".format(key))
                    counter -= 1
                else:
                    command = random.randint(0, 16)
            else:
                if (command > 5):
                    key = random.randint(5000, 7000)
                    value = random.randint(0, 5000)
                    pushed.append((key, value))
                    file.write("push {} {}\n".format(key, value))
                    counter += 1
                else:
                    key, value = random.choice(pushed)
                    file.write("search {}\n".format(key))


        for i in range(int(number) / 4):

            command = random.randint(0, 20)

            if (command > 18):
                if counter >= 0:
                    key, value = random.choice(pushed)
                    file.write("pop {}\n".format(key))
                    counter -= 1
                else:
                    command = random.randint(0, 16)
            else:
                if (command > 5):
                    key = random.randint(3000, 5000)
                    value = random.randint(0, 5000)
                    pushed.append((key, value))
                    file.write("push {} {}\n".format(key, value))
                    counter += 1
                else:
                    key, value = random.choice(pushed)
                    file.write("search {}\n".format(key))

        for i in range(int(number) / 4):

            command = random.randint(0, 20)

            if (command > 18):
                if counter >= 0:
                    key, value = random.choice(pushed)
                    file.write("pop {}\n".format(key))
                    counter -= 1
                else:
                    command = random.randint(0, 16)
            else:
                if (command > 5):
                    key = random.randint(0, 3000)
                    value = random.randint(0, 5000)
                    pushed.append((key, value))
                    file.write("push {} {}\n".format(key, value))
                    counter += 1
                else:
                    key, value = random.choice(pushed)
                    file.write("search {}\n".format(key))


        # file.write("print")




