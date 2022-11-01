-- 코드를 입력하세요
SELECT A.FOOD_TYPE, A.REST_ID, A.REST_NAME, A.FAVORITES from REST_INFO A
    join (SELECT FOOD_TYPE, max(FAVORITES) as FAVORITES from REST_INFO group by FOOD_TYPE) B
    on A.FAVORITES=B.FAVORITES and A.FOOD_TYPE=B.FOOD_TYPE
    order by A.FOOD_TYPE desc