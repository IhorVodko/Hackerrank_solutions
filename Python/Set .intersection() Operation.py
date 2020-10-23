#Problem: https://www.hackerrank.com/challenges/py-set-intersection-operation/problem


num1 = int(input())
st_eng = set(input().split())

num2= int(input())
st_franch = set(input().split())

print(len(st_eng.intersection(st_franch)))
