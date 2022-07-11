n, m = map(int, input().split())

order = []
for i in range(m):
    order.append(list(map(int, input().split())))
train = [['0']*20 for _ in range(n)]
# 1 i x : i번째 기차에(1 ≤ i ≤ N) x번째 좌석에(1 ≤ x ≤ 20) 사람을 태워라. 이미 사람이 타있다면 , 아무런 행동을 하지 않는다.
# 2 i x : i번째 기차에 x번째 좌석에 앉은 사람은 하차한다. 만약 아무도 그자리에 앉아있지 않았다면, 아무런 행동을 하지 않는다.
# 3 i : i번째 기차에 앉아있는 승객들이 모두 한칸씩 뒤로간다. k번째 앉은 사람은 k+1번째로 이동하여 앉는다. 만약 20번째 자리에 사람이 앉아있었다면 그 사람은 이 명령 후에 하차한다.
# 4 i : i번째 기차에 앉아있는 승객들이 모두 한칸씩 앞으로간다. k번째 앉은 사람은 k-1 번째 자리로 이동하여 앉는다. 만약 1번째 자리에 사람이 앉아있었다면 그 사람은 이 명령 후에 하차한다.
for o in order:
    i = o[1] - 1
    if o[0] == 1:
        train[i][o[2]-1] = '1'
    elif o[0] == 2:
        train[i][o[2]-1] = '0'
    elif o[0] == 3:
        train[i] = ['0'] + train[i][:-1]
    elif o[0] == 4:
        train[i] = train[i][1:] + ['0']
ans = set()
for t in train:
    ans.add(''.join(t))
print(len(ans))