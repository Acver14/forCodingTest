from collections import deque, defaultdict

def solution(topping):
    answer = 0
    topping = deque(topping)
    toppings = defaultdict(int)
    for t in topping:
        toppings[t] += 1
    
    ch = set()
    i = 0
    for i in range(len(topping)):
        t = topping.popleft()
        ch.add(t)
        toppings[t] -= 1
        if toppings[t] == 0:
            del toppings[t]
        if len(ch) == len(toppings.keys()):
            answer += 1
    
    return answer