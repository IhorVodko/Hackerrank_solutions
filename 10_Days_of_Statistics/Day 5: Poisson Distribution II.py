#Problem: https://www.hackerrank.com/challenges/s10-poisson-distribution-2/problem?h_r=next-challenge&h_v=zen


# E(X) = lambda_
# Var(X) = lambda_
# mu(X) = lambda_

lambda_1, lambda_2 = 0.88, 1.55

expected_cost_A = 160 + 40 * (lambda_1 + lambda_1**2)
expected_cost_B = 128 + 40 * (lambda_2 + lambda_2**2)

print('%.3f' %expected_cost_A)
print('%.3f' %expected_cost_B)
