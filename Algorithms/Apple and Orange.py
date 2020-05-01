#Problem: https://github.com/IhorVodko/Hackerrank_solutions/new/master/Algorithms


def countApplesAndOranges(s, t, a, b, apples, oranges):
    print(sum([1 for x in apples if (x+a)>=s and (x+a)<=t]))
    print(sum([1 for x in oranges if (x+b)>=s and (x+b)<=t]))
