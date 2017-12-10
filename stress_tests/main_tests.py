import random


my_file = open("/home/anton/projects/bmstu/algs/structures/input", "w")

my_file.write("elist\n")

count = 1000

my_file.write(str(count) + "\n")

for i in range(count):
    my_file.write("push " + str(random.randint(1, 10000)) + ' ' + str(random.randint(1, 10000)) + "\n")