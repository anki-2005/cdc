# Write your MySQL query statement below
select round(count(*) / (select count(distinct(player_id)) from Activity),2) as fraction from
Activity a1 join (select player_id,min(event_date) as first_date from Activity group by player_id) as t on t.player_id=a1.player_id and a1.event_date=DATE_ADD(t.first_date, INTERVAL 1 DAY); ;