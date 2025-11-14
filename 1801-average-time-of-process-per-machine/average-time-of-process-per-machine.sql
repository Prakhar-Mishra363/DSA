# Write your MySQL query statement below
SELECT res.machine_id , round(avg(res.totalTime),3) as processing_time
FROM
(select a1.machine_id  ,((a2.timestamp)- (a1.timestamp)) as totalTime
FROM Activity a1
JOIN Activity a2
ON a1.machine_id = a2.machine_id AND a1.process_id = a2.process_id 
AND a1.activity_type = 'start' AND a2.activity_type = 'end') as res
GROUP BY res.machine_id ;
