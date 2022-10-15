# Write your MySQL query statement below
# select p.product_id, p.product_name from Product p, (
#     select product_id from sales where sale_date between '2019-01-01' and '2019-03-31'
# ) u where p.product_id = u.product_id and p.product_id not in 
# (select product_id from sales where sale_date > '2019-03-31'
#     union
# select product_id from sales where sale_date < '2019-01-01')

SELECT product_id, product_name 
FROM Product 
WHERE product_id IN
(SELECT product_id
FROM Sales
GROUP BY product_id
HAVING MIN(sale_date) >= '2019-01-01' AND MAX(sale_date) <= '2019-03-31')

