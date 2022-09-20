from collections import deque
import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
N = int(input())
card = list(map(int, input().split()))
ans = 0

def func(flag, sum1, sum2, card_list, front, back):
    global ans
    if front < back:
        if flag:
            num1, num2 = card_list[back], card_list[back-1]
            func(flag, sum1+num1, sum2+num2, card_list, front, back-2)
        else:
            num1, num2 = card_list[back], card_list[back-1]
            func(flag, sum1+num1, sum2+num2, card_list, front, back-2)
            
            num1, num2 = card_list[front], card_list[back]
            func(True, sum1+num1, sum2+num2, card_list, front+1, back-1)
            
            num1, num2 = card_list[back], card_list[front]
            func(True, sum1+num1, sum2+num2, card_list, front+1, back-1)
    else:
        ans = max(ans, sum1)
        
func(False, 0, 0, card, 0, N-1)
print(ans)