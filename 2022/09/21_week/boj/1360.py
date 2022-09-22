N = int(input())
operations = []
for i in range(N):
    operations.append(list(input().split()))
ans = ''
undo_time = ''
for i in reversed(range(N)):
    oper, val, time = operations[i]
    if undo_time != '' and undo_time <= int(time):
        continue
    
    if oper == 'undo':
        undo_time = int(time) - int(val)
        
    else:
        undo_time = ''
        ans = val + ans
        
print(ans)