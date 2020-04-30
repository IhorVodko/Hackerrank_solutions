#Problem: https://www.hackerrank.com/challenges/game-with-cells/problem


def gameWithCells(n, m):
    return int((n+n%2)*(m+m%2)/4)
