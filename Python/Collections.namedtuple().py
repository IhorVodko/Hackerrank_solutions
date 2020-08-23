#Problem: https://www.hackerrank.com/challenges/py-collections-namedtuple/problem

from collections import namedtuple

num = int(input())
columns = input().split()

sum_marks = 0
for _ in range(num):
    students = namedtuple('student', columns)
    col0, col1, col2, col3 = input().split()
    student = students(col0, col1, col2, col3)
    sum_marks += int(student.MARKS)

print(sum_marks/num)
