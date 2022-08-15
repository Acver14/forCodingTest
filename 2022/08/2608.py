val_dict = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}
com_dict = {
    'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900
}
total_dict = {
    'I': 1,
    'IV': 4,
    'V': 5,
    'IX': 9,
    'X': 10,
    'XL': 40,
    'L': 50,
    'XC': 90,
    'C': 100,
    'CD': 400,
    'D': 500,
    'CM': 900,
    'M': 1000
    
}
def romeToArab(string):
    num = 0
    for key, val in com_dict.items():
        cnt = string.count(key)
        if cnt > 0:
            string = string.replace(key, '')
            num += cnt * val
    for a in string:
        num += val_dict[a]
    return num

num = romeToArab(input()) + romeToArab(input())
ans = ''
print(num)
for key, val in reversed(total_dict.items()):
    if num >= val:
        cnt = num // val
        ans += key * cnt
        num -= val * cnt
print(ans)