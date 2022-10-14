from collections import deque
def solution(order):
    answer = 0
    # 큐
    container = deque([i+1 for i in range(len(order))])
    # 스택
    sub_con = []
    while order:
        if container and order[answer] == container[0]:
            container.popleft()
            answer += 1
        elif sub_con and order[answer] == sub_con[-1]:
            sub_con.pop()
            answer += 1
        elif container and order[answer] > container[0]:
            sub_con.append(container.popleft())
        else:
            break
    return answer