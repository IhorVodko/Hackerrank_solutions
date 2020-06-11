--Problem https://www.hackerrank.com/challenges/weather-observation-station-17/problem


SELECT ROUND(long_w, 4)
FROM STATION
WHERE lat_n > 38.7780
ORDER BY lat_n
LIMIT 1;
