# s = input()

# num = 0
# ans = ''
# for i in s:
#     if i < 'A' or i > 'Z':
#         num += int(i)
#     else:
#         ans += i
        
# ans = sorted(ans)
# ans = "".join(ans)

# print(ans + str(num))

data = input()
result = []
value = 0

for x in data:
    if x.isalpha():
        result.append(x)
    else:
        value += int(x)
        
result.sort()

if value != 0:
    result.append(str(value))

print("".join(result))