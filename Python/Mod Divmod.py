#Problem: https://www.hackerrank.com/challenges/python-mod-divmod/problem


a = int(input())
b = int(input())

tuple_ = divmod(a, b)
print(*[*tuple_, tuple_], sep = '\n')
