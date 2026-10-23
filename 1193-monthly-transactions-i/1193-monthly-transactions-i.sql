-- Write your PostgreSQL query statement below
select TO_CHAR(trans_date, 'yyyy-mm') as month , 
       country ,
       count(*) as trans_count,
       sum( CASE WHEN state = 'approved' THEN 1 ELSE 0 END) as approved_count,
       sum(amount) as trans_total_amount,
       sum(CASE WHEN state = 'approved' THEN amount ELSE 0 END) as approved_total_amount

from transactions
group by TO_CHAR(trans_date, 'yyyy-mm') , country