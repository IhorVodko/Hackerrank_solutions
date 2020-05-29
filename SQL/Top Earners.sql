--Problem: https://github.com/IhorVodko/Hackerrank_solutions/edit/master/SQL/Top%20Earners.sql


SELECT (months * salary) as earnings, COUNT(*)
FROM EMPLOYEE
GROUP BY earnings
ORDER BY earnings DESC
LIMIT 1;
