#problem: https://www.hackerrank.com/challenges/s10-least-square-regression-line/problem


n = 5
X = [95, 85, 80, 70, 60]
Y = [85, 95, 70, 65, 70]

b = (n*sum([X[i]*Y[i] for i in range(n)]) - sum(X)*sum(Y)) / \
    (n*sum([X[i]**2 for i in range(n)]) - sum(X)**2)
a = sum(Y)/n - b*(sum(X)/n)

print(round(a + b*80, 3))
