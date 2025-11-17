# Write your MySQL query statement below
SELECT x,y,z,
IF(x+y > z AND x>0 AND y>0 AND z>0 AND ((x+z > y)) AND
 ((y+z > x)),'Yes','No') AS triangle
FROM Triangle
