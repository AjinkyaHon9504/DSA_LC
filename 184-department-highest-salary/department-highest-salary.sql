# Write your MySQL query statement below
select d.name as Department,e.name as Employee ,e.salary as Salary
from Employee e
join Department d 
on d.id=e.departmentId
having e.salary = (SELECT MAX(e2.salary)
    FROM Employee e2
    WHERE e2.departmentId = e.departmentId); 