--Problem: https://www.hackerrank.com/challenges/draw-the-triangle-2/problem


SET @n = 0;
SELECT REPEAT('* ', @n := @n + 1)
FROM information_schema.tables
WHERE @n < 20;
