#Problem https://www.hackerrank.com/challenges/write-a-function/problem
#Score 10


def is_leap(year):
    if (year%4 == 0 and year%100 != 0) or (year%100 == 0 and year%400 == 0):
        leap = True
    else: 
        leap = False
    return leap
