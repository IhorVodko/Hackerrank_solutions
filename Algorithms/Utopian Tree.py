#Problem: https://www.hackerrank.com/challenges/utopian-tree/problem


def utopianTree(n):

    i = 0
    h = 0
    while i <= n:
        if i%2 == 0:
            h += 1
            i += 1
        else:
            h *= 2
            i += 1
            
    return h
