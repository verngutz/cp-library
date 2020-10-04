#!/usr/bin/python3
import colorama, itertools, os.path, sys, subprocess, termcolor
from random import choice, randint, random, sample, shuffle
from string import ascii_lowercase, ascii_uppercase

colorama.init()

tests = []

def make_single_test():
    ...

def print_test(test, input_file=sys.stdout):
    def printf(*args, **kwargs):
        print(*args, **kwargs, file=input_file)

    ...

for i in range(3):
    print_test(make_single_test())
    print(termcolor.colored(f'Printed sample test {i}.', 'yellow'))
input(termcolor.colored('Press ENTER to continue', 'magenta', attrs=['bold']))

for i, test in enumerate(tests or (make_single_test() for i in itertools.count()), start=1):
    print(termcolor.colored(f'Test Case {i}', 'blue'))
    with open('input.txt', 'w') as input_file:
        print_test(test, input_file)

    solution_file = sys.argv[1] if len(sys.argv) > 1 else 'solution' if os.path.exists('solution') else 'solution.py'
    solution_command = f'./{solution_file} < input.txt > output.txt'
    print(termcolor.colored(solution_command, 'blue'))
    subprocess.run(solution_command, shell=True, check=True)

    brute_file = sys.argv[2] if len(sys.argv) > 2 else 'brute.py'
    brute_command = f'./{brute_file} < input.txt > expected.txt'
    print(termcolor.colored(brute_command, 'blue'))
    subprocess.run(brute_command, shell=True, check=True)

    try:
        subprocess.run('cmp --silent output.txt expected.txt', shell=True, check=True)
    except subprocess.CalledProcessError:
        print(termcolor.colored(f'test failed', 'red', attrs=['bold']))
        for file in ('input', 'output', 'expected'):
            print(termcolor.colored(f'{file}:', 'yellow'))
            subprocess.run(f'cat {file}.txt', shell=True)
        break

    print(termcolor.colored(f'{i} test cases passed', 'green', attrs=['bold']))
