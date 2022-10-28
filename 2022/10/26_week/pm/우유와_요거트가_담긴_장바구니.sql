-- 코드를 입력하세요
SELECT distinct a.CART_ID from CART_PRODUCTS a
    join (SELECT CART_ID, NAME from CART_PRODUCTS where NAME='Milk') b
    on a.CART_ID = b.CART_ID
    where a.NAME='Yogurt'
    order by a.CART_ID