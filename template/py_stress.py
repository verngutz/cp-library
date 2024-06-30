#!/usr/local/bin/pypy3
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

subprocess.run('sudo mount -t tmpfs -o size=1024m tmpfs /mnt/tmpfs', shell=True, check=True)

for i, test in enumerate(tests or (make_single_test() for i in itertools.count()), start=1):
    print(termcolor.colored(f'Test Case {i}', 'blue'))
    with open('/mnt/tmpfs/input.txt', 'w') as input_file:
        print_test(test, input_file)

    solution_file = sys.argv[1] if len(sys.argv) > 1 else 'solution' if os.path.exists('solution') else 'solution.py'
    solution_command = f'./{solution_file} < /mnt/tmpfs/input.txt > /mnt/tmpfs/output.txt'
    print(termcolor.colored(solution_command, 'blue'))
    try:
        subprocess.run(solution_command, shell=True, check=True)
    except subprocess.CalledProcessError:
        print(termcolor.colored('solution runtime error', 'red', attrs=['bold']))
        print(termcolor.colored('input:', 'yellow'))
        subprocess.run(f'cat /mnt/tmpfs/input.txt', shell=True)
        raise

    brute_file = sys.argv[2] if len(sys.argv) > 2 else 'brute.py'
    brute_command = f'./{brute_file} < /mnt/tmpfs/input.txt > /mnt/tmpfs/expected.txt'
    print(termcolor.colored(brute_command, 'blue'))
    try:
        subprocess.run(brute_command, shell=True, check=True)
    except subprocess.CalledProcessError:
        print(termcolor.colored('brute runtime error', 'red', attrs=['bold']))
        print(termcolor.colored('input:', 'yellow'))
        subprocess.run(f'cat /mnt/tmpfs/input.txt', shell=True)
        raise

    try:
        subprocess.run('cmp --silent /mnt/tmpfs/output.txt /mnt/tmpfs/expected.txt', shell=True, check=True)
    except subprocess.CalledProcessError:
        print(termcolor.colored('test failed', 'red', attrs=['bold']))
        for file in ('input', 'output', 'expected'):
            print(termcolor.colored(f'{file}:', 'yellow'))
            subprocess.run(f'cat /mnt/tmpfs/{file}.txt', shell=True)
            subprocess.run(f'cp /mnt/tmpfs/{file}.txt ./{file}.txt', shell=True)
        break

    print(termcolor.colored(f'{i} test cases passed', 'green', attrs=['bold']))
