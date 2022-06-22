def solution(s):
    answer = 1
    
    stack = []
    for i in s:
        if stack:
            if stack[-1] == i:
                stack.pop()
                continue
        stack.append(i)
    if stack:
        answer = 0
    return answer