def solution(number, k):
    number = list(number)
    stack = []
    
    for n in number:
        while stack and stack[-1] < n:
            if k > 0:
                stack.pop()
                k -= 1
            else:
                break
        stack.append(n)
    while k > 0:
        stack.pop()
        k -= 1
    
    return ''.join(stack)