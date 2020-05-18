#Problem: https://www.hackerrank.com/challenges/s10-the-central-limit-theorem-3/problem


z = 1.96
std = 80
n = 100
mean = 500

margin_of_error = z * (std / n**0.5)

print(round(mean - margin_of_error, 2))
print(round(mean + margin_of_error, 2))
