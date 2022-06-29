from collections import defaultdict
def solution(participant, completion):
    answer = ''
    result = defaultdict(int)
    for k in participant:
        result[k] += 1
    for k in completion:
        result[k] -= 1
        
    for k, v in result.items():
        if v > 0:
            return k