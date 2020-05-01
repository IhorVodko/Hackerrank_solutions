#Problem: https://www.hackerrank.com/challenges/angry-professor/problem


def angryProfessor(k, a):

    not_late = sum([1 for x in a if x <= 0])
    if not_late < k:
        return 'YES'
    else:
        return 'NO'
