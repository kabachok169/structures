#!/usr/bin/env python

import sys


if __name__ == "__main__":

    filename = "input"
    structure = sys.argv[1]

    with open(filename, 'r') as file:
        lines = file.read().split('\n')
        lines[0] = structure
    file.close()

    with open(filename, 'w') as file:
        for line in lines:
            file.write(line + '\n')
