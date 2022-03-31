from audioop import reverse
from sys import stdin
from collections import deque
import re

input = stdin.readline

t = int(input().strip())
for i in range(t):
    p = input().strip()
    n = int(input().strip())
    arr = []
    if n == 0:
        input()
        arr = deque([])
    else : arr = deque(re.findall("\d+", input()))
    
    _reversed = False
    isError = False
    for s in p:
        if s == 'R':
            _reversed = not _reversed
        elif s == 'D':
            if arr:
                if _reversed:
                    arr.pop()
                else:
                    arr.popleft()
            else:
                isError = True
                break
    if isError:
        print('error')
    else:
        print('[', end='')
        ans = ''
        if _reversed:
            while arr:
                ans += str(arr.pop())+','
        else:
            while arr:
                ans += str(arr.popleft())+','
        print(ans[:-1],end='')
        print(']')
