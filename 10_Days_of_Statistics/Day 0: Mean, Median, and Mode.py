#Problme: https://www.hackerrank.com/challenges/s10-basic-statistics/problem


import numpy as np
from scipy import stats

count = int(input())
arr =  [int(x) for x in input().strip().split()]

mean_ = np.mean(arr)
median_ = np.median(arr) 
mode_ = int(stats.mode(arr)[0])

print(mean_, median_, mode_, sep = '\n')
