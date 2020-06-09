--Problem: https://www.hackerrank.com/challenges/weather-observation-station-15/problem


SELECT ROUND(long_w, 4)
FROM STATION
WHERE lat_n < 137.2345
ORDER BY lat_n DESC
LIMIT 1;
