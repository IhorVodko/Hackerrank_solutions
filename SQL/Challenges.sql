--Problem https://www.hackerrank.com/challenges/challenges/problem


SELECT H.hacker_id, H.name, COUNT(C.challenge_id) AS challenges_created
FROM Hackers H
JOIN Challenges C ON C.hacker_id = H.hacker_id
GROUP BY H.hacker_id, H.name
HAVING challenges_created = 
    (SELECT COUNT(C2.challenge_id) AS c_max
     FROM Challenges AS C2
     GROUP BY C2.hacker_id 
     ORDER BY c_max DESC LIMIT 1)
OR challenges_created IN 
    (SELECT DISTINCT c_compare AS c_unique
     FROM (SELECT H2.hacker_id, H2.name, COUNT(challenge_id) AS c_compare
           FROM Hackers H2
           JOIN Challenges C3 ON C3.hacker_id = H2.hacker_id
           GROUP BY H2.hacker_id, H2.name) temp1
     GROUP BY c_compare
     HAVING COUNT(c_compare) = 1)
ORDER BY challenges_created DESC, H.hacker_id;
