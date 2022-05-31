-- 外连接
select
	p.FirstName, p.LastName, a.City, a.State
from
	Person p
left outer join
	Address a
on
	p.PersonId = a.PersonId
