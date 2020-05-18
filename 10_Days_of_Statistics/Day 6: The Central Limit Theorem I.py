#Problem: https://github.com/IhorVodko/Hackerrank_solutions/new/master/10_Days_of_Statistics


import math

weight,n,mean,std= 9800, 49, 205, 15
def CLT(weight,n,mean,std):
    mean_mu = n * mean
    std_mu = (n**0.5) * std     
    return round(0.5 * (1 + math.erf((weight - mean_mu) / (std_mu * (2**0.5)))), 4)

print(CLT(weight,n,mean,std))
