def solution(s):
    answer = [-1 for _ in range(len(s))]
    pos = {}
    for idx, val in enumerate(s):
        prev = pos.get(val, -1)
        if prev != -1:
            answer[idx] = idx - prev
        else:
            answer[idx] = -1
        pos[val] = idx
        
    return answer