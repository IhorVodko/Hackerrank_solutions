#Problem: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem


def beautifulDays(i, j, k):

    result = [1 for day in [*range(i, j+1)] if abs((day - int(str(day)[::-1]))) % k == 0]

    return sum(result)
