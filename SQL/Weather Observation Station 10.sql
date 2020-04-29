--Problme: https://www.hackerrank.com/challenges/weather-observation-station-10/problem


SELECT distinct CITY
FROM STATION
WHERE CITY REGEXP '[^aeiouAEIOU]$';
