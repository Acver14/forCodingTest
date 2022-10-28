-- 코드를 입력하세요
SELECT i.ANIMAL_ID, i.ANIMAL_TYPE, i.NAME from ANIMAL_INS i
    join ANIMAL_OUTS o
    on i.ANIMAL_ID = o.ANIMAL_ID
    where i.SEX_UPON_INTAKE like 'Intact%' and
    (o.SEX_UPON_OUTCOME like 'Spayed%' or
    o.SEX_UPON_OUTCOME like 'Neutered%')
    order by i.ANIMAL_ID

# 중성화를 거치지 않은 동물은 성별 및 중성화 여부에 Intact, 
# 중성화를 거친 동물은 Spayed 또는 Neutered라고 표시되어있습니다