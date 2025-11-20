# Write your MySQL query statement below
SELECT 
    s.student_id,
    s.student_name,
    q.subject_name,
    COUNT(e.subject_name) AS attended_exams
FROM Students s
JOIN Subjects q 
    ON 1 = 1
LEFT JOIN Examinations e
    ON s.student_id = e.student_id
    AND q.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, q.subject_name
ORDER BY s.student_id, q.subject_name;