#Problem: https://github.com/IhorVodko/Hackerrank_solutions/new/master/Algorithms


def compareTriplets(a, b):
    al = 0
    bo = 0
    for i in range(len(a)):
        if a[i] > b[i]:
            al += 1
        elif a[i] < b[i]:
            bo += 1
    return [al, bo]
