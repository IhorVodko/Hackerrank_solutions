#Problem: https://www.hackerrank.com/challenges/calendar-module/problem


# Enter your code here. Read input from STDIN. Print output to STDOUT
import calendar

m, d, y  = map(int, input().strip().split())
print([*calendar.day_name][calendar.weekday(y, m, d)].upper())
