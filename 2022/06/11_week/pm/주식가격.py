def solution(prices):
    answer = [0]*len(prices)
    stack = []
    idx = 0
    while prices:
        while stack and stack[-1][0] > prices[0]:
            _, sidx = stack.pop()
            answer[sidx] = idx-sidx
        stack.append((prices.pop(0), idx))
        idx += 1
    while stack:
        _, sidx = stack.pop()
        answer[sidx] = idx-sidx-1

    return answer