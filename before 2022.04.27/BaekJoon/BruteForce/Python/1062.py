import sys
input = sys.stdin.readline

n, k = map(int, input().split())


a = ord('a')

words = []
answer = 0
learn = [0] * 26
for i in range(n):
    temp = set(input().rstrip()[4:-4])
    words.append(temp)
for c in ('a', 'c', 'i', 'n', 't'):
    learn[ord(c) - a] = 1
    
if k < 5:
    print(0)
    exit()
elif k == 26:
    print(n)
    exit()
    
def dfs(idx, cnt):
    global answer

    if cnt == k - 5:
        readcnt = 0
        for word in words:
            check = True
            for w in word:
                if not learn[ord(w) - a]:
                    check = False
                    break
            if check:
                readcnt += 1
        answer = max(answer, readcnt)
        return

    for i in range(idx, 26):
        if not learn[i]:
            learn[i] = True
            dfs(i, cnt + 1)
            learn[i] = False


dfs(0, 0)
print(answer)

    
