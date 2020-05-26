--Problem: https://www.hackerrank.com/challenges/the-blunder/problem


SELECT CEIL(AVG(salary) - AVG(REPLACE(salary, '0', '')))
FROM EMPLOYEES;
