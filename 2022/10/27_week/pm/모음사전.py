def solution(word):
    global diclist
    diclist = []
    d = ['A', 'E', 'I', 'O', 'U']
    dfs('', d)
    return diclist.index(word)

def dfs(s, d):
    global diclist
    diclist.append(s)
    if len(s) < 5:
        for i in range(5):
            dfs(s+d[i], d)