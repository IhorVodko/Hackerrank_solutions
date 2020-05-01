#Problem: https://github.com/IhorVodko/Hackerrank_solutions/new/master/Algorithms


def pickingNumbers(a):

    maximum = 0
    for k in a:
        c1 = a.count(k)
        c2 = a.count(k-1)
        maximum = max((c1+c2), maximum)
        
    return maximum
