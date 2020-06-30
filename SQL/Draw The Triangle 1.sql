--Problem: https://github.com/IhorVodko/Hackerrank_solutions/edit/master/SQL/Draw%20The%20Triangle%201.sql


SET @number = 21;
SELECT REPEAT('* ', @number := @number - 1) 
FROM information_schema.tables 
WHERE @number > 0;
