# -- 코드를 입력하세요
SELECT a.CATEGORY, b.MAX_PRICE, a.PRODUCT_NAME from FOOD_PRODUCT a
    join (SELECT max(PRICE) as MAX_PRICE, CATEGORY from FOOD_PRODUCT
          where CATEGORY IN ('과자', '국', '김치', '식용유')
          group by CATEGORY
         ) as b
    on a.CATEGORY = b.CATEGORY and a.PRICE=b.MAX_PRICE
    order by a.PRICE desc

          