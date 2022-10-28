-- 코드를 입력하세요
# 년, 월, 성별 별로 상품을 구매한 회원수
SELECT YEAR(SALES_DATE) as YEAR, MONTH(SALES_DATE) as MONTH, GENDER, count(distinct(o.USER_ID)) as USERS from ONLINE_SALE o
join (SELECT * from USER_INFO where GENDER is not null) u
on o.USER_ID = u.USER_ID
group by YEAR(SALES_DATE), MONTH(SALES_DATE), u.GENDER
order by YEAR(SALES_DATE), MONTH(SALES_DATE), u.GENDER asc