#Problem: https://www.hackerrank.com/challenges/py-set-union/problem


num1 = int(input())
st_eng = set(input().split())

num2= int(input())
st_franch = set(input().split())

print(len(st_eng.union(st_franch)))
