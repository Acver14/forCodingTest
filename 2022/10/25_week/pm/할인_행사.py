from collections import defaultdict

def solution(want, number, discount):
    answer = 0
    limit = len(discount) - 9
    wants = defaultdict(int)
    for i, v in enumerate(want):
        wants[v] = number[i]
        
    for i in range(limit):
        wants_copy = wants.copy()
        for j in range(10):
            if wants_copy[discount[i+j]] > 0:
                wants_copy[discount[i+j]] -= 1
        isAnswer = True
        for val in wants_copy.values():
            if val > 0:
                isAnswer = False
                break
        if isAnswer:
            print(i)
            answer += 1
        
    return answer