from collections import deque
def solution(p):
    answer = ''
    if p == '':
        return ''
    if isCorrect(p):
        return p
    u, v = divide(p)
    if isCorrect(u):
        return u + solution(v)
    else:
        tmp =''
        for i in range(1, len(u)-1):
            if u[i] == '(':
                tmp += ')'
            else:
                tmp += '('
        return '(' + solution(v) + ')' + tmp

def divide(string):
    cnt = 0
    ret = ''
    s = ''
    if string == '':
        return '', ''
    string = deque(list(string))
    while string:
        s = string.popleft()
        if s == '(':
            cnt += 1
        else:
            cnt -= 1
        ret += s
        if cnt == 0:
            return ret, ''.join(string)
    return ret, ''

def isCorrect(string):
    stk = []
    for s in string:
        if s == '(':
            stk.append('(')
        else:
            if stk:
                stk.pop()
            else:
                return False
    return True
            