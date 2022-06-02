select
ifnull((select 
	distinct salary
from
	Employee
order by
	salary desc
limit 1, 1), null) as SecondHighestSalary;






-- 更慢
select max(Salary) SecondHighestSalary 
from Employee
where Salary < (select max(Salary) from Employee)





