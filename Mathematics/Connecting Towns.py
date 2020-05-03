#Problem: https://www.hackerrank.com/challenges/connecting-towns/problem


import functools

def connectingTowns(n, routes):
    
    n_routes = functools.reduce(lambda x,y: x*y, routes) 
    modular = int(''.join([str(x) for x in range(1,8)]))
    return n_routes % modular
