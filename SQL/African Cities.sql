--Problem: https://www.hackerrank.com/challenges/african-cities/problem


SELECT CI.name
FROM CITY AS CI
JOIN COUNTRY AS CO
ON CI.countrycode = CO.code
WHERE CO.continent = 'Africa';
