import matplotlib.pyplot as plt
import subprocess
import random



def average(vector):
    return sum(vector) / len(vector)


def very_bad_func(x, y):
    k = (average([xi * yi for xi in x for yi in y]) - average(x) * average(y)) / (average([xi ** 2 for xi in x]) - average(x) ** 2)
    b = average(y) - k * average(x)
    return (k, b)


