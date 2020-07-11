#Problem: https://www.hackerrank.com/challenges/swap-case/problem


def swap_case(s):

    solution = ''.join([char.lower() if char.isupper() else char.upper() for char in s])
    
    return solution
