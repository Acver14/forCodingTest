import sys
input = sys.stdin.readline

from collections import deque
n,m = map(int,input().split())
L = [list(map(int,input().split())) for _ in range(n)]
D = [(0,-1),(-1,-1),(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1)]

cloud = deque()

def move(cloud,d,s):
    new_cloud = deque()
    while cloud:
        x,y = cloud.popleft()
        x_n, y_n = (x+D[d-1][0]*s)% n, (y+D[d-1][1]*s)%n
        new_cloud.append((x_n,y_n))
    return new_cloud

def copy(new_cloud):
    F = [(-1,-1),(1,1),(-1,1),(1,-1)]
    for i in new_cloud:
        cnt = 0
        x,y = i[0],i[1]
        for j in F:
            x_n,y_n = x+j[0],y+j[1]
            if(0<=x_n<n and 0<=y_n<n and L[x_n][y_n]!=0 ):
                cnt += 1
        L[x][y] += cnt
    return

cloud = deque([[n-1, 0], [n-1, 1], [n-2, 0], [n-2, 1]])

for i in range(m):
    d,s = map(int,input().split())
    new_cloud = move(cloud,d,s)
    for i in new_cloud:
        L[i[0]][i[1]] += 1
    cloud = deque()
    copy(new_cloud)
    for i in range(n):
        for j in range(n):
            if( (i,j) not in new_cloud and L[i][j] > 1):
                L[i][j] -=2
                cloud.append((i,j))

print(sum(sum(b) for b in L))