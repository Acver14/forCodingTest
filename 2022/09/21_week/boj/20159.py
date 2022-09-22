N = int(input())
arr = list(map(int, input().split()))

# 밑장 빼기를 안했을 때 정훈이 카드의 합
junghun_origin_sum = 0
for i in range(N):
    if i % 2 == 0:
        junghun_origin_sum += arr[i]
ans = junghun_origin_sum
junghun_sum = junghun_origin_sum

# (정훈이 차례에서) 맨 아래에서부터 밑장 빼기 했을 때 합 어떤지
for i in range(N-1, 0, -2):
    junghun_sum += arr[i]
    junghun_sum -= arr[i-1]
    ans = max(ans, junghun_sum)


junghun_sum = junghun_origin_sum
# 상대 차례에서 맨 아래부터 밑장 빼기를 했을 때 합이 어떤지
for i in range(N-2, 1, -2):
    junghun_sum -= arr[i]
    junghun_sum += arr[i-1]
    ans = max(ans, junghun_sum)

print(ans)