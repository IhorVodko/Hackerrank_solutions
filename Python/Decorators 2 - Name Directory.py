#Problem: https://www.hackerrank.com/challenges/decorators-2-name-directory/problem


import operator

def person_lister(f):
    def inner(people):
        # complete the function 
        return map(f, sorted([[e[0], e[1], int(e[2]), e[3]] \
            for e in people],key=operator.itemgetter(2)))      
    return inner

@person_lister
def name_format(person):
    return ("Mr. " if person[3] == "M" else "Ms. ") + person[0] + " " + person[1]

if __name__ == '__main__':
    people = [input().split() for i in range(int(input()))]
    print(*name_format(people), sep='\n')
