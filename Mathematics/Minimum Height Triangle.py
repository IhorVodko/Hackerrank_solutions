#Problme: https://www.hackerrank.com/challenges/lowest-triangle/problem


from math import ceil

def lowestTriangle(base, area):
    return ( ceil((2*area/base)) )
