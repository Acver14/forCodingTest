# Solution 함수에게 2개의 벡터가 매개변수로 주어진다. 
# 매개변수로 주어진 두개의 벡터는 pop 과 push 2가지 작업을 할 수 있다
# pop : 선택된 하나의 벡터의 첫번재 값을 뽑아낸다
# push : pop을 통해 뽑아낸 값을 반대편 벡터 마지막에 추가한다

# 위 pop - push 작업은 반드시 연속적으로 이루어지며 이를 1번의 작업이라고 정의한다

# 이떄 몇번의 pop - push 작업을 통해 두 벡터의 합을 같게 만들 수 있는지 result 값에 담아 반환하시오. ( 두 벡터의 합을 같게 만들 수 없는 경우 -1을 반환한다 )


# 입출력 예시
# queue1	            queue2	    result
# [3, 2, 7, 2]      [4, 6, 5, 1] 	    2
# [1, 2, 1, 2] 	    [1, 10, 1, 2]	    7
# [1, 1]	         [1, 5]	        -1

from collections import deque
que1 = [3, 1, 3]
que2 = [1, 3]

que1 = deque(que1)
que2 = deque(que2)
lim = len(que1) * len(que2) + 1
s1 = sum(que1)
s2 = sum(que2)
cnt = 0

while s1 != s2:
    if que1 and que2 and cnt <= lim:
        if s1 < s2:
            que1.append(que2.popleft())
        elif s1 > s2:
            que2.append(que1.popleft())
    else:
        cnt = -1
        break
        
    cnt += 1
    s1, s2 = sum(que1), sum(que2)
print(cnt)