#Problem: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem


def divisibleSumPairs(n, k, ar):
    count = 0
    start = 0
    while start < n:
        for i in ar[(start+1):]:
            if (ar[start] + i)%k == 0:
                count += 1
        start += 1
    return count   
