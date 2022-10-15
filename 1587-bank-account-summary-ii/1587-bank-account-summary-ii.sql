# Write your MySQL query statement below

select u.name, t.balance from Users u, (select account, SUM(amount) as balance from Transactions group by account) t where t.balance > 10000 and u.account = t.account;