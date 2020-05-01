#Problem: https://www.hackerrank.com/challenges/birthday-cake-candles/problem


def birthdayCakeCandles(ar):
    count = 0
    max_ = max(ar)
    for i in ar:
        if max_ == i:
            count+=1
    return count
