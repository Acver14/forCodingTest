def isRight(s):
    stack = []
    for i in range(len(s)):
        if s[i] == '(':
            stack.append(s[i])
        else:
            if stack:
                stack.pop()
            else:
                return False
    if stack:
        return False
    return True

def func(w):
    if not w:
        return ''
    
    l, r = 0, 0
    idx = -1
    for i in range(len(w)):
        if w[i] == '(':
            l += 1
        else:
            r += 1
        if l == r:
            idx = i
            break
            
    u, v = w[:idx+1], w[idx+1:]
    print(str(isRight(u)))
    if isRight(u):
        return u + func(v)
    else:
        temp = ''
        print(u)
        for i in range(1, len(u)-1):
            if u[i] == '(':
                temp += ')'
            else:
                temp += '('
        print(temp)
        return '(' + func(v) + ')' + temp

def solution(p):
    answer = func(p)
    return answer