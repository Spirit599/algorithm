# Write your MySQL query statement below
select Email
from Person
group by Email
having count(Email) > 1

select distinct(a.Email)
from Person a
join Person b
on a.Email = b.Email and a.Id != b.Id