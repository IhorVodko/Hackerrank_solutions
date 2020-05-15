--Problem: https://www.hackerrank.com/challenges/what-type-of-triangle/problem


SELECT 
CASE
    WHEN A = B AND A = C THEN "Equilateral"
    WHEN A >= (B + C) OR B >= (A + C) OR C >= (A + B) THEN "Not A Triangle"
    WHEN A = B OR A = C OR B = C THEN "Isosceles"
    ELSE "Scalene"
END
FROM TRIANGLES;
