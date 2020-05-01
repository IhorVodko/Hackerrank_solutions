#Problem: https://www.hackerrank.com/challenges/kangaroo/problem


def kangaroo(x1, v1, x2, v2):
    if v1 <= v2:
        return 'NO'
    else:
        solution = (x1-x2)/(v2-v1)
        if solution > 0 and (x1-x2)%(v2-v1)==0:
            return 'YES'
        else:
            return 'NO'
