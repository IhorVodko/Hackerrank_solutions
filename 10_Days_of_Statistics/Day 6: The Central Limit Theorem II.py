#Problem: https://www.hackerrank.com/challenges/s10-the-central-limit-theorem-2/problem


import math

tickets, n, mean, sd = 250, 100, 2.4, 2.0

def CLT(tickets, n, mean, sd):

    mean_mu = n * mean
    std_mu = (n**0.5) * std    
    
    return round(0.5 * (1 + math.erf((weight - mean_mu) / (std_mu * (2**0.5)))), 4)

print(CLT(tickets, n, mean, std))
