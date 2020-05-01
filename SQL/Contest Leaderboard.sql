--Problem: https://www.hackerrank.com/challenges/contest-leaderboard/problem


SELECT hacker_id,
    (SELECT name 
     FROM Hackers H
     WHERE H.hacker_id = temp1.hacker_id) Name,
     SUM(score) total_score
FROM (SELECT hacker_id, MAX(score) score 
      FROM Submissions 
      GROUP BY hacker_id, challenge_id) temp1
GROUP BY hacker_id
HAVING total_score > 0
ORDER BY total_score DESC, HACKER_ID;
