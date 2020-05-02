--Problem: https://www.hackerrank.com/challenges/placements/problem


SELECT S.Name
FROM Students S
    JOIN Packages P1
    ON S.ID = P1.ID
    JOIN Friends F
    ON S.ID = F.ID
    JOIN Packages P2
    ON F.Friend_ID = P2.ID
WHERE P1.Salary < P2.Salary
ORDER BY P2.Salary;
