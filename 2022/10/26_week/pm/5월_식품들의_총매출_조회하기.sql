-- 코드를 입력하세요
# 식품 ID, 식품 이름, 총매출
SELECT p.PRODUCT_ID, p.PRODUCT_NAME, sum(p.PRICE*o.AMOUNT) as TOTAL_SALES from FOOD_PRODUCT p
    join FOOD_ORDER o
    on p.PRODUCT_ID = o.PRODUCT_ID
    where YEAR(o.PRODUCE_DATE)=2022 and MONTH(o.PRODUCE_DATE)=5
    group by p.PRODUCT_ID
    order by TOTAL_SALES desc, p.PRODUCT_ID asc
    