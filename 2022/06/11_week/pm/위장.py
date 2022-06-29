from collections import defaultdict

def solution(clothes):
    answer = 1
    cloth = defaultdict(int)
    for c in clothes:
        cloth[c[1]] += 1

    for v in cloth.values():
        answer *= v+1

    return answer-1
