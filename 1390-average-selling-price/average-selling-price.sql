# Write your MySQL query statement below
SELECT Inter.product_id,
CASE 
    WHEN SUM(Inter.totalPrice) IS NULL THEN 0.00 ELSE
    ROUND(SUM(Inter.totalPrice)/SUM(Inter.units),2)  
END AS average_price
FROM
(SELECT P.product_id, (P.price * U.units) as totalPrice,
U.units
FROM Prices P
LEFT JOIN UnitsSold U
ON P.product_id = U.product_id
AND U.purchase_date >= P.start_date
AND U.purchase_date <= P.end_date) AS Inter
GROUP BY Inter.product_id;