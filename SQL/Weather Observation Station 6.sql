--Problem: https://www.hackerrank.com/challenges/weather-observation-station-6/problem


SELECT DISTINCT CITY 
FROM STATION
WHERE CITY RLIKE '^[aeiouAEIOU]';
