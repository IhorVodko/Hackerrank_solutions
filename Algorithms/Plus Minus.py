#Problem: https://www.hackerrank.com/challenges/plus-minus/problem


def plusMinus(arr):
    m = 0
    z = 0
    p = 0
    for i in arr:
        if i < 0:
            m+=1
        elif i == 0:
            z+=1
        else:
            p+=1
    sum_ = m + z + p
    print(round(p/sum_,6), round(m/sum_,6), round(z/sum_,6), sep='\n')
