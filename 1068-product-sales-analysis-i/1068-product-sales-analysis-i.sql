# Write your MySQL query statement below
SELECT product_name,year,price
FROM Sales 
Left Join Product on Sales.product_id=Product.product_id