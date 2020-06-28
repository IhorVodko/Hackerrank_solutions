--Problem: https://www.hackerrank.com/challenges/average-population-of-each-continent/problem


SELECT  CO.continent, FLOOR(AVG(CI.population))
FROM CITY AS CI
JOIN COUNTRY AS CO
ON CI.countryCode = CO.code
GROUP BY CO.continent;
