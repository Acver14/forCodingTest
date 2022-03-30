from sys import stdin

for _ in range(int(stdin.readline())):
    string = stdin.readline().strip()
    left, right = [], []
    for s in string:
        if s == '<':
            if left:
                right.append(left.pop())
        elif s == '>':
            if right:
                left.append(right.pop())
        elif s == '-':
            if left:
                left.pop()
        else:
            left.append(s)
    left.extend(reversed(right))
    print(''.join(left))
    
from sys import stdin
for _ in range(int(stdin.readline())):
    typing = stdin.readline().strip()
    left, right = [], []
    for typ in typing:
        if typ == '<':
            if left:
                right.append(left.pop())
        elif typ == '>':
            if right:
                left.append(right.pop())
        elif typ == '-':
            if left:
                left.pop()
        else:
            left.append(typ)
    left.extend(reversed(right))
    print(''.join(left))