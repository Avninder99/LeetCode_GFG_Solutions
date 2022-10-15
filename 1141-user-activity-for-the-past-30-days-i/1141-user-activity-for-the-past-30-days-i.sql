# Write your MySQL query statement below
select activity_date as day, COUNT(DISTINCT user_id) as active_users
from Activity
where activity_date BETWEEN ('2019-07-27' - INTERVAL 29 DAY) and '2019-07-27'
group by activity_date