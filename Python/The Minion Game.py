#Problem https://www.hackerrank.com/challenges/the-minion-game/problem
#Score   40


def minion_game(string):
    # your code goes here
    vow = 'AEIOU'

    k = 0
    s = 0
    l = len(string)
    
    for i in range(l):
        if string[i] in vow:
            k += l - i
        else:
            s += l - i
    
    if k > s:
        print(f'Kevin {k}')
    elif k < s:
        print(f'Stuart {s}')
    else:
        print('Draw')
