#!/usr/bin/python3
import sys, subprocess, itertools
from random import choice, randint, sample
from string import ascii_lowercase, ascii_uppercase

tests = []

def make_single_test():
    ...

def print_test(test, input_file=sys.stdout):
    def printf(*args):
        print(*args, file=input_file)

    ...

if len(sys.argv) == 1:
    print_test(make_single_test())
else:
    for i, test in enumerate(tests or (make_single_test() for i in itertools.count())):
        print("\033[1;34;40m")
        print("Test Case {}".format(i))
        with open('input.txt', 'w') as input_file:
            print_test(test, input_file)

        for command in [
            "./{} < input.txt > output1.txt".format(sys.argv[1]),
            "./{} < input.txt > output2.txt".format(sys.argv[2])]:
            print(command)
            subprocess.run(command, shell=True, check=True)

        try:
            subprocess.run("cmp --silent output1.txt output2.txt", shell=True, check=True)
        except subprocess.CalledProcessError:
            print("\033[1;31;40m", end='')
            print("test failed")
            break

        print("\033[1;32;40m", end='')
        print("{} test cases passed".format(i))
