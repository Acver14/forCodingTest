def solution(queue1, queue2):
    answer = 0
    queue = queue1 + queue2
    _sum = sum(queue1)
    target = sum(queue) // 2
    i, j = 0, len(queue1) - 1
    
    while i < len(queue) and j < len(queue):
        if _sum == target:
            return answer
        elif _sum < target and j < len(queue) - 1:
            j += 1
            _sum += queue[j]
        else:
            _sum -= queue[i]
            i += 1
        answer += 1
    return -1