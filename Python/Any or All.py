#Problem: https://www.hackerrank.com/challenges/any-or-all/problem


_ = int(input())
cases = input().split()

print( all((int(num) > 0 for num in cases)) and
        any((num == num[::-1] for num in cases))
)
