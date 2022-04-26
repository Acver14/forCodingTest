import sys
input = sys.stdin.readline

n, k = map(int, input().split())
klist = list(map(int, input().split()))

tab = [0] * n
ans = 0


for i in range(len(klist)):
    clear = False
    if klist[i] in tab:
        continue
    for l in range(len(tab)):
        if tab[l] == 0:
            tab[l] = klist[i]
            clear = True
            break
    if not clear:
        val, lastidx = 0, 0
        for j in range(0, n):
            cnt = 0
            for l in range(i+1, k):
                if tab[j] == klist[l]:
                    break
                cnt += 1
        if cnt > lastidx:
            val = j
            lastidx = cnt
        ans += 1
        tab[val] = klist[i]
print(ans)
