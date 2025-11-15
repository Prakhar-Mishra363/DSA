# Write your MySQL query statement below
SELECT  R.contest_id,
ROUND((COUNT(DISTINCT R.user_id)/COUNT(DISTINCT U.user_id))*100,2) AS percentage
FROM Register R
CROSS JOIN Users U
group by R.contest_id
ORDER BY percentage DESC, R.contest_id

