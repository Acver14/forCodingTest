-- 코드를 입력하세요
SELECT o.ANIMAL_ID, o.NAME from ANIMAL_OUTS o
    join ANIMAL_INS i
    on o.ANIMAL_ID = i.ANIMAL_ID
    order by DATEDIFF(i.DATETIME, o.DATETIME) asc
    limit 2