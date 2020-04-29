#Problam: https://www.hackerrank.com/challenges/weather-observation-station-3/problem


SELECT distinct CITY
FROM STATION
WHERE ID % 2 = 0;
