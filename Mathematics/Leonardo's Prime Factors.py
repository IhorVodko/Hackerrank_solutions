#Problem: https://www.hackerrank.com/challenges/leonardo-and-prime/problem


import math

def isPrime(x):
    if x < 2:
        return False
    elif x == 2 or x == 3:
        return True
    else:
        if x%2 == 0:
            return False
        elif x%3 == 0:
            return False
        max_div = int(math.sqrt(x)) + 1
        inc = 2
        div = 5
        while div <= max_div:
            if x%div == 0:
                return False
            div += inc
            inc = 6 - inc
        return True
    
def primeCount(n):
    prod = 1
    count = 0
    for i in range(2, n+1):
        if isPrime(i):
            if (prod*i) <= n:
                prod *= i
                count += 1
            else:
                break
    return count
