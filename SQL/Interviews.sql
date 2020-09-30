--problem: https://www.hackerrank.com/challenges/interviews/problem


SELECT con.contest_id, con.hacker_id, con.name, SUM(sub_lj.total_submissions),   
    SUM(sub_lj.total_accepted_submissions), SUM(vie_lj.total_views),
    SUM(vie_lj.total_unique_views)
FROM Contests AS con
JOIN Colleges AS col
 ON con.contest_id = col.contest_id
JOIN Challenges AS cha
 ON col.college_id = cha.college_id
LEFT JOIN (SELECT sub.challenge_id, SUM(sub.total_submissions) AS total_submissions,
    SUM(sub.total_accepted_submissions) AS total_accepted_submissions 
    FROM Submission_Stats AS sub
    GROUP BY sub.challenge_id) AS sub_lj
 ON cha.challenge_id = sub_lj.challenge_id
LEFT JOIN (SELECT vie.challenge_id, SUM(vie.total_views) AS total_views,
    SUM(vie.total_unique_views) AS total_unique_views
    FROM View_Stats AS vie
    GROUP BY vie.challenge_id) AS vie_lj
 ON cha.challenge_id = vie_lj.challenge_id
GROUP BY con.contest_id, con.hacker_id, con.name
HAVING SUM(sub_lj.total_submissions) + SUM(sub_lj.total_accepted_submissions) +      
    SUM(vie_lj.total_views) + SUM(vie_lj.total_unique_views) > 0
ORDER BY con.contest_id;
