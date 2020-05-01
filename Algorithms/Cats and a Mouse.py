#Problem: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem


def catAndMouse(x, y, z):

    cat_a = abs(z-x)
    cat_b = abs(z-y)
    if cat_a < cat_b:
        return('Cat A')
    elif cat_a > cat_b:
        return('Cat B')
    else: 
        return('Mouse C')
