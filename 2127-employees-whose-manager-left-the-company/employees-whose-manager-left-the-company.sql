# Write your MySQL query statement below
select e.employee_id
from Employees e 
left join Employees m 
on e.manager_id = m.employee_id
where e.salary<30000
AND e.manager_id IS NOT NULL
and m.employee_id is null
order by e.employee_id;