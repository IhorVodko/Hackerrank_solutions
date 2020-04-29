--Problem: https://www.hackerrank.com/challenges/weather-observation-station-9/problem


SELECT DISTINCT CITY 
FROM STATION
WHERE CITY RLIKE '^[^aieouAIEOU]';
