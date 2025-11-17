# Write your MySQL query statement below
SELECT (SELECT *
FROM MyNumbers
GROUP BY num
HAVING COUNT(*)=1
ORDER BY num DESC
LIMIT 1) AS num
