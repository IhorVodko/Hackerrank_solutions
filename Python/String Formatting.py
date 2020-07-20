#Problem: https://www.hackerrank.com/challenges/python-string-formatting/problem


def print_formatted(number):
    # your code goes here
    length = len(bin(number)[2:])
    for num in range(1, number+1):
        dec_ = str(num)
        oct_ = oct(num)[2:]
        hex_ = hex(num).upper()[2:]
        bin_ = bin(num)[2:]
        print(' '.join(map(lambda x: x.rjust(length), [dec_, oct_, hex_, bin_])) )


if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
