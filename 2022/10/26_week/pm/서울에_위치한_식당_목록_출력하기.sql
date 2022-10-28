-- 코드를 입력하세요
# 식당 ID, 식당 이름, 음식 종류, 즐겨찾기수, 주소, 리뷰 평균 점수를
SELECT i.REST_ID, i.REST_NAME, i.FOOD_TYPE, i.FAVORITES, i.ADDRESS, round(avg(r.REVIEW_SCORE), 2) as SCORE from REST_INFO i
    join REST_REVIEW r
    on i.REST_ID = r.REST_ID
    where i.ADDRESS like '서울%'
    group by i.REST_ID
    order by SCORE desc, FAVORITES desc