#Problem: https://github.com/IhorVodko/Hackerrank_solutions/new/master/Algorithms


def getMoneySpent(keyboards, drives, b):

    return max([sum([x,y]) for x in keyboards for y in drives if sum([x,y]) <= b]+[-1])
