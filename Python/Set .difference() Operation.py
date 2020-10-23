#Problem: https://www.hackerrank.com/challenges/py-set-difference-operation/problem


num1 = int(input())
st_eng = set(input().split())

num2= int(input())
st_franch = set(input().split())

print(len(st_eng.difference(st_franch)))
