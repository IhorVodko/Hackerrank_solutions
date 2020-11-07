#Problem: https://www.hackerrank.com/challenges/zipped/problem


studsTotal, subjsTotal = map(int, input().split())

scores_list = []
for i in range(subjsTotal):
    scores_list.append(map(float, input().split()))

students_scores = zip(*scores_list)
studs_avg_scores = [sum(student_scores)/subjsTotal for student_scores in    
                    students_scores]

print(*studs_avg_scores, sep = '\n')
