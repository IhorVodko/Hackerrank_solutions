--Problem: https://www.hackerrank.com/challenges/weather-observation-station-7/problem


SELECT DISTINCT CITY
FROM STATION
WHERE RIGHT(CITY, 1) IN ('a', 'e', 'i', 'o', 'u');
