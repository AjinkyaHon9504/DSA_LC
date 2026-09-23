# Write your MySQL query statement below
with feb_orders as (
    select product_id,unit 
    from Orders 
    where order_date >='2020-02-01'
    and order_date <'2020-03-01'
)
select p.product_name,sum(f.unit)as unit
from feb_orders f
join Products p 
on f.product_id=p.product_id
group by p.product_id,p.product_name
having sum(f.unit)>=100;