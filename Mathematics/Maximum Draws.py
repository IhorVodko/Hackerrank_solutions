#Problem: https://www.hackerrank.com/challenges/maximum-draws/problem


def maximumDraws(n):
    if n == 1:
        ans = 2
    else:
        ans = n+1
    return ans
