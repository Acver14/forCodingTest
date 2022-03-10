# x, y = input()

# x = int(ord(x)) - ord('a') + 1
# y = int(y)

# dx = [2, 2, -2, -2, 1, -1, 1, -1]
# dy = [1, -1, 1, -1, -2, -2, 2, 2]

# cnt = 0
# for i in range(8):
#     nx = x + dx[i]
#     ny = y + dy[i]
#     if nx < 1 or nx > 8 or ny < 1 or ny > 8: continue
#     cnt += 1
    
# print(cnt)


input_data = input()
row = int(input_data[1])
column = int(ord(input_data[0])) - int(ord('a')) + 1

steps = [(-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1)]

cnt = 0
for step in steps:
    next_row = row + step[0]
    next_col = column + step[1]
    
    if(next_row >= 1 and next_row <= 8 and next_col >= 1 and next_col <= 8):
        cnt += 1

print(cnt)