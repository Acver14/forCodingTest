from collections import deque
def solution(queue1, queue2):
    global answer
    answer = 0
    ans1 = func(deque(queue1.copy()), deque(queue2.copy()))
    ans2 = func(deque(queue2.copy()), deque(queue1.copy()))
    print(ans1, ans2)
    if ans1 == -1:
        answer = ans2
    elif ans2 == -1:
        answer = ans1
    else:
        answer = min(ans1, ans2)
    return answer

def func(queue1, queue2):
    ret = 0
    while queue2:
        print(queue1, queue2, sum(queue1), sum(queue2))
        if sum(queue1) == sum(queue2):
            return ret
        queue1.append(queue2.popleft())
        ret += 1
    return -1