--Problem: https://www.hackerrank.com/challenges/weather-observation-station-12/problem


SELECT DISTINCT CITY 
FROM STATION
WHERE CITY REGEXP "^[^aeiouAEIOU]" AND CITY REGEXP "[^aeiouAEIOU]$";
