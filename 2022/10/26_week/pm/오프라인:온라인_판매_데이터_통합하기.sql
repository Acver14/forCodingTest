-- 코드를 입력하세요
# 2022년 3월의 오프라인/온라인 상품 판매 데이터의 판매 날짜, 상품ID, 유저ID, 판매량
SELECT
    date_format(SALES_DATE, '%Y-%m-%d') as SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
    from ONLINE_SALE
    where YEAR(SALES_DATE)=2022 and MONTH(SALES_DATE)=3
union
SELECT
    date_format(SALES_DATE, '%Y-%m-%d') as SALES_DATE, PRODUCT_ID, NULL as USER_ID, SALES_AMOUNT
    from OFFLINE_SALE
    where YEAR(SALES_DATE)=2022 and MONTH(SALES_DATE)=3
order by SALES_DATE asc, PRODUCT_ID asc, USER_ID asc

