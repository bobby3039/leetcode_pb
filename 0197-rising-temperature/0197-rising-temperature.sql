# Write your MySQL query statement below
select a.id
from weather as a inner join weather as b
ON DATEDIFF(a.recordDate, b.recordDate) = 1
where a.temperature > b.temperature