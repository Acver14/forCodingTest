from collections import deque

N = int(input())
card = list(map(int, input().split()))
card = deque(card)
ans = 0

def back(flag, sum1, sum2, card_list):
    global ans
    if card_list:
        if flag:
            num1, num2 = card_list.pop(), card_list.pop()
            back(flag, sum1+num1, sum2+num2, card_list)
            card_list.append(num1)
            card_list.append(num2)
        else:
            num1, num2 = card_list.pop(), card_list.pop()
            back(flag, sum1+num1, sum2+num2, card_list)
            card_list.append(num1)
            card_list.append(num2)
            
            num1, num2 = card_list.popleft(), card_list.pop()
            back(True, sum1+num1, sum2+num2, card_list)
            card_list.appendleft(num1)
            card_list.append(num2)
            
            num1, num2 = card_list.pop(), card_list.popleft()
            back(True, sum1+num1, sum2+num2, card_list)
            card_list.append(num1)
            card_list.appendleft(num2)
    else:
        ans = max(ans, sum1)
back(False, 0, 0, card)
print(ans)