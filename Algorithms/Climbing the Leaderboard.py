#Problem: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem


def climbingLeaderboard(scores, alice):

    leaders = sorted(set(scores), reverse = True)
    list_= []
    l = len(leaders)
    for i in alice:
        while l>0 and i>=leaders[l-1]:
            l -= 1
        list_.append(l+1)
        
    return list_ 
