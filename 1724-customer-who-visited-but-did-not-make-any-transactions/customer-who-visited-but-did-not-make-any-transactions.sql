# Write your MySQL query statement below
SELECT V.customer_id,count(V.visit_id) AS count_no_trans
FROM Transactions AS T
RIGHT JOIN Visits AS V
ON T.visit_id = V.visit_id
WHERE T.transaction_id IS NULL
GROUP BY V.customer_id;
