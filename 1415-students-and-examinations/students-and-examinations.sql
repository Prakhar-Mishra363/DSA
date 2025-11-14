# Write your MySQL query statement below
SELECT S.student_id,S.student_name,Sub.subject_name,
count(E.subject_name) AS attended_exams
FROM Students S
CROSS JOIN Subjects Sub
LEFT JOIN Examinations E
ON E.student_id  = S.student_id 
AND Sub.subject_name = E.subject_name
GROUP BY S.student_id,S.student_name,Sub.subject_name
ORDER BY S.student_id,S.student_name;
