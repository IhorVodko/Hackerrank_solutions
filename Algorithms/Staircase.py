#Problem: https://github.com/IhorVodko/Hackerrank_solutions/new/master/Algorithms


def staircase(n):
    [print(' '*(n-(i+1))+'#'*(i+1)) for i in range(n)]
