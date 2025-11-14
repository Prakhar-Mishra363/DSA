# Write your MySQL query statement below
SELECT unique_id,name
FROM EmployeeUNI AS Emp
RIGHT JOIN Employees AS E
ON Emp.id = E.id;