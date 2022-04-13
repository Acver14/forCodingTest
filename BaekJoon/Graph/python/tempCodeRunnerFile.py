from sys import stdin
from collections import defaultdict
input = stdin.readline

case = 0
while True:
    case += 1
    arr = []
    reading = True
    while reading:
        row = input().rstrip()
        if not row: break
        for i in row.split('  '):
            i, j = map(int, i.split())
            if i == 0 and i == 0: 
                reading = False
                break
            if i == -1 and j == -1:
                exit()
            arr.append((i,j))
    
    check = defaultdict(int)
    for i in arr:
        if i[0] != i[1]:
            check[i[1]] += 1
    root_num = 0
    isTree = True
    for i in check.values():
        if i == 0:
            root_num += 1
        elif i > 1:
            isTree = False
        
    if isTree and root_num == 1:
        print('Case %d is a tree.' %case)
    else: 
        print('Case %d is not a tree.' %case)