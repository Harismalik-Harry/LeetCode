# Write your MySQL query statement below
select e.unique_id ,eu.name from EmployeeUNI  e right join Employees eu  on e.id=eu.id;