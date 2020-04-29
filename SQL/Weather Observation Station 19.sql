--Problem: https://www.hackerrank.com/challenges/weather-observation-station-19/problem


SELECT ROUND(SQRT(POWER(MIN(LAT_N) - MAX(LAT_N), 2) + POWER(MIN(LONG_W) - MAX(LONG_W), 2)), 4)
FROM STATION;
