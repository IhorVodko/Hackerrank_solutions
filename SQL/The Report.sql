--Priblem: https://www.hackerrank.com/challenges/the-report/problem


SELECT IF(Grades.Grade >= 8, Students.Name, NULL), Grades.Grade, Students.Marks
FROM Grades, Students
WHERE Students.Marks BETWEEN Grades.Min_Mark AND Grades.Max_Mark
ORDER BY Grades.Grade DESC, Students.Name, Students.Marks;
