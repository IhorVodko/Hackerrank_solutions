#Problem: https://www.hackerrank.com/challenges/s10-poisson-distribution-1/problem


from math import exp, factorial

# mu == E(x) == lambda_
lambda_ = 2.5 
k = 5

poisson_prob = (lambda_ ** k) * exp(-lambda_) / factorial(k)
print('%.3f' %poisson_prob)
