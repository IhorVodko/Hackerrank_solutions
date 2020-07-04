#Problem: https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem


if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())

dict_ = {}
print( sorted(list(set(arr)))[-2] )
