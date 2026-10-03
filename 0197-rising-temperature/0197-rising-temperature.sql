# Write your MySQL query statement below
select a.id
from weather as a inner join weather as b
on a.temperature > b.temperature
where DATEDIFF(a.recordDate, b.recordDate) = 1