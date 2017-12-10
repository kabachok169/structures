import matplotlib.pyplot as plt
import subprocess
import random



def average(vector):
    return sum(vector) / len(vector)


def very_bad_func(x, y):
    k = (average([xi * yi for xi in x for yi in y]) - average(x) * average(y)) / (average([xi ** 2 for xi in x]) - average(x) ** 2)
    b = average(y) - k * average(x)
    return (k, b)


def generate(n, k):
    result = []
    for i in range(n):
        result.append(random.randint(0, k-1))
    return result


def to_string(vector):
    result = ''
    for element in vector:
        result += str(element)
    return result

