/* Write your PL/SQL query statement below */

select t.name as Customers from 
customers t 
where t.id not in (select c.id from customers c join orders o on c.id = o.customerId);



