#Problem: https://www.hackerrank.com/challenges/drawing-book/problem


def pageCount(n, p):

    return min(p//2, n//2-p//2)
