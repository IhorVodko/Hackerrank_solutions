#Problem: https://www.hackerrank.com/challenges/diagonal-difference/problem


def diagonalDifference(arr):
    d1_sum = sum(arr[i][i] for i in range(len(arr)))
    d2_sum = sum(arr[i][len(arr)-i-1] for i in range(len(arr)))
    return abs(d1_sum-d2_sum)
