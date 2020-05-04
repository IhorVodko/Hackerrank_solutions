#Problem: https://www.hackerrank.com/challenges/symmetric-pairs/problem


SELECT f1.X, f1.Y
FROM Functions f1
WHERE f1.X = f1.Y 
GROUP BY f1.X, f1.Y 
HAVING COUNT(*) > 1
UNION
SELECT f1.X, f1.Y
FROM Functions f1
WHERE EXISTS(SELECT X, Y
             FROM Functions
             WHERE f1.X = Y AND f1.Y = X AND f1.X < X)
ORDER BY X;
