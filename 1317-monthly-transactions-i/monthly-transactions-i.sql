# Write your MySQL query statement below
SELECT DATE_FORMAT(trans_date,'%Y-%m') as month,
country,count(*) as trans_count,
SUM(IF(state  like "approved",1,0)) as approved_count ,
SUM(amount) as trans_total_amount,
SUM(CASE WHEN state like "approved" THEN amount ELSE 0 END) AS approved_total_amount
FROM Transactions
GROUP BY YEAR(trans_date),month(trans_date),country