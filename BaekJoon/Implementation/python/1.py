n = int(input())
# min, sec = 59, 59

# cnt = 0
# while True:
#     if min==0 and sec == 0:
#         n -= 1
#         min = 60
#     if sec == 0:
#         min -= 1
#         sec = 60
#     if sec != 0: sec -=1
#     if '3' in str(n) + str(min) + str(sec):
#         cnt += 1

#     if n==0 and min==0 and sec==2: break

# print(cnt)

cnt = 0
for i in range(n+1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i) + str(j) + str(k):
                cnt+=1
print(cnt)