#Problem: https://www.hackerrank.com/challenges/py-check-subset/problem

for _ in range(int(input())):

    A_count = int(input())
    A = set(input().split())
    B_count = int(input())
    B = set(input().split())
    
    print(A.intersection(B) == A)


