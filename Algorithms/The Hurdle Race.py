#Problem: https://www.hackerrank.com/challenges/the-hurdle-race/problem


def hurdleRace(k, height):

    drop = (max(height) - k)
    if drop >= 0:
        sol = drop
    else :
        sol = 0
        
    return sol
