from sys import stdin
from collections import defaultdict
input = stdin.readline

start, mid, end = input().rstrip().split()
format = '%H:%M'
start = int("".join(start.split(':')))
mid = int("".join(mid.split(':')))
end = int("".join(end.split(':')))
check = defaultdict(int)

ans = 0
while True:
    chat = input().rstrip()
    if not chat: break
    name = chat.split()[1]
    time = int("".join(chat.split()[0].split(':')))
    if time <= start:
        check[name] = 1
    elif mid <= time <= end:
        if check[name] > 0:
            check[name] *= -1
            ans += 1
        
print(ans)