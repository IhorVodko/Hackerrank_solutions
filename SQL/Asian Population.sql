--Problem https://github.com/IhorVodko/Hackerrank_solutions/edit/master/SQL/Asian%20Population.sql


SELECT SUM(CI.population)
FROM CITY as CI
JOIN COUNTRY as CO
ON CI.countrycode = CO.code
WHERE CO.continent = "Asia";
