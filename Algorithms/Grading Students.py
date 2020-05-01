#Problem: https://www.hackerrank.com/challenges/grading/problem


def gradingStudents(grades):
    new_grades = []
    for i in grades:
        if i < 38:
            new_grades.append(i)
        elif i%5==0:
            new_grades.append(i)
        else:
            for k in range(i, i+5):
                if k%5==0:
                    if k - i < 3:
                        new_grades.append(k)
                    else:
                        new_grades.append(i)
    return new_grades
