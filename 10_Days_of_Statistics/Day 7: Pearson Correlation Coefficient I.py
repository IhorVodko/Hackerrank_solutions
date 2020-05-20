#Problem: https://www.hackerrank.com/challenges/s10-pearson-correlation-coefficient/problem


n = int(input())
x = [float(x) for x in input().strip().split()]
y = [float(x) for x in input().strip().split()]

x_mu, y_mu = [sum(i)/n for i in [x, y]]

std_x = (sum([(i - x_mu)**2 for i in x]) / n)**0.5
std_y = (sum([(i - y_mu)**2 for i in y]) / n)**0.5

cov = sum([(x[i] - x_mu)*(y[i] - y_mu) for i in  range(n)]) / n

corr = cov / (std_x * std_y)

print(round(corr, 3))

