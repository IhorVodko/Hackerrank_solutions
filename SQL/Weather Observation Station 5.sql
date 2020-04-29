--Problem: https://www.hackerrank.com/challenges/weather-observation-station-5/problem


SELECT CITY, length(CITY)
FROM STATION
ORDER BY LENGTH(CITY), CITY
LIMIT 1;

SELECT CITY, length(CITY)
FROM STATION
ORDER BY LENGTH(CITY) DESC, CITY
LIMIT 1;
