# n개의 정수로 된 순서 S= (s1, s2, ..., sn)가 있다. 여기서 si ≠ sj이고, 1 ≤ si ≤ n이다.
# S로부터 새로운 순서 R = (r1, r2, ..., rn)을 얻을 수 있는데, 여기서 ri는 S의 부분 순서 {s1, s2, ..., si-2, si-1} 중에서 si보다 작은 수의 개수이다.

# n = 10인 경우의 예를 보자. S = (6, 4, 3, 5, 1, 2, 7, 8, 9, 10)이라면 R = (0, 0, 0, 2, 0, 1, 6, 7, 8, 9)이 된다. 
# 어떤 순서 R이 주어질 때, 여러분은 R을 이용하여 S를 찾는 프로그램을 작성하어야 한다. 경우에 따라서는 R로부터 S를 찾는 것이 불가능할 수 있다. 
# 예를 들어, 만약 n = 5이고, R = (0, 2, 2, 0, 1)이라면 이런 R에 대응하는 S는 존재하지 않는다.
T = int(input())
for _ in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    used = [False for _ in range(N+1)]
    ans = [0 for _ in range(N)]
    isPossible = True
    for i in reversed(range(N)):
        k = arr[i] + 1
        for _ in range(k, N+1):
            if used[k]:
                k+=1
                continue
            cnt = 0
            for t in range(1, k):
                if not used[t]:
                    cnt += 1
            if cnt == arr[i]:
                used[k] = True
                ans[i] = str(k)
                break
            k += 1
        if k > N:
            isPossible = False
            break
    if isPossible:
        print(' '.join(ans))
    else:
        print('IMPOSSIBLE')
    
# 6 4 3 5 1 2 8 9 7 10
# 10 9 8 7 6 5 4 3 2 1
# IMPOSSIBLE