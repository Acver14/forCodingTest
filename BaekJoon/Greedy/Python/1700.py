import sys
input = sys.stdin.readline

n, k = map(int, input().split())
klist = list(map(int, input().split()))

par = [102] * k
for k in range(len(klist)):
    for i in range(k+1, len(klist)):
        if klist[k] == klist[i]:
            par[k] = i
            break

tab = [0] * n
cnt = 0
for k in range(len(klist)):
    clear = False
    if klist[k] in tab:
        continue
    for i in range(len(tab)):
        if tab[i] == 0:
            tab[i] = klist[k]
            clear = True
            break
    if not clear:
        max = -1
        for i in range(k-n, k):
            if par[i] > max:
                max = i
        idx = 0
        if max != -1:
            idx = tab.index(klist[max])
        tab[idx] = klist[k]
        cnt += 1
        continue
print(cnt)