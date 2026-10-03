# Write your MySQL query statement below
select a.machine_id , round(avg(b.timestamp - a.timestamp),3) as processing_time
from activity as a inner join activity as b
on a.activity_type = 'start' AND b.activity_type = 'end' AND a.process_id = b.process_id AND a.machine_id = b.machine_id
group by a.machine_id