#https://www.hackerrank.com/challenges/python-sort-sort/problem


#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    k = int(input())

    arr_sorted = sorted(arr, key = lambda elem: elem[k])
    [print(*sub_arr) for sub_arr in arr_sorted]
