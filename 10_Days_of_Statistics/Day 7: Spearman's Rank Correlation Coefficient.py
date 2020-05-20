#Prblem: https://www.hackerrank.com/challenges/s10-spearman-rank-correlation-coefficient/problem


n = int(input())
x = [float(i) for i in input().strip().split()]
y = [float(i) for i in input().strip().split()]

r_x = [(sorted(x).index(i) + 1) for i in x]
r_y = [(sorted(y).index(i) +1) for i in y]

r_xy = 1 - ((6 * sum([(r_x[i] - r_y[i])**2 for i in range(n)])) / (n * (n**2 - 1)))

print(round(r_xy, 3))
