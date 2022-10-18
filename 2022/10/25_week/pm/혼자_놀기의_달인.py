def solution(cards):
    global isOpend
    answer = 0
    
    cards = [0] + cards
    isOpend = [False for _ in range(len(cards))]
    sum_list = []
    for i in range(1, len(cards)):
        sum_list.append(dfs(i, cards, 0))
    sum_list.sort()
    if sum_list[-2] > 0:
        answer = sum_list[-2] * sum_list[-1]
    return answer

def dfs(idx, cards, s):
    if isOpend[idx]:
        return s
    isOpend[idx] = True
    return dfs(cards[idx], cards, s+1)