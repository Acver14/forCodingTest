from collections import deque
T = int(input())
gear = [[0]]
for _ in range(T):
    gear.append(deque(list(input())))
    
k = int(input())
operations = []
for _ in range(k):
    operations.append(list(map(int, input().split())))
    
r, l = 2, 6

def rotate(target, dir):
    global gear
    if target > 1:
        if gear[target][l] != gear[target-1][r]:
            rotateLeft(target-1, dir*(-1))
    if target < T:
        if gear[target][r] != gear[target+1][l]:
            rotateRight(target+1, dir*(-1))
    if dir == 1:
        gear[target].appendleft(gear[target].pop())
    elif dir == -1:
        gear[target].append(gear[target].popleft())

def rotateLeft(target, dir):
    global gear
    if target > 1:
        if gear[target][l] != gear[target-1][r]:
            rotateLeft(target-1, dir*(-1))
    if dir == 1:
        gear[target].appendleft(gear[target].pop())
    else:
        gear[target].append(gear[target].popleft())
        
def rotateRight(target, dir):
    global gear
    if target < T:
        if gear[target][r] != gear[target+1][l]:
            rotateRight(target+1, dir*(-1))
    if dir == 1:
        gear[target].appendleft(gear[target].pop())
    else:
        gear[target].append(gear[target].popleft())
        
for target, dir in operations:
    rotate(target, dir)
    
ans = 0
for g in gear:
    if g[0] == '1':
        ans += 1
print(ans)
    