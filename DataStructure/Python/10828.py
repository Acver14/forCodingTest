class stack:
    value = [0 for i in range(10001)]
    size = 0
    
    def isEmpty(self):
        if self.size == 0: return True
        else: return False
        
    def push(self, x):
        self.value[self.size] = x
        self.size += 1
        
    def pop(self):
        if self.isEmpty():
            print(-1)
        else:
            print(self.value[self.size-1])
            self.size -= 1
            
    def top(self):
        if self.isEmpty():
            print(-1)
        else:
            print(self.value[self.size-1])
            
    def getSize(self):
        print(self.size)
    
from sys import stdin
n = int(stdin.readline())

s = stack()

for i in range(n):
    cmd = stdin.readline().split()
    if cmd[0].startswith('push'):
        s.push(int(cmd[1]))
    elif cmd[0].startswith('pop'):
        s.pop()
    elif cmd[0].startswith('top'):
        s.top()
    elif cmd[0].startswith('size'):
        s.getSize()
    elif cmd[0].startswith('empty'):
        if s.isEmpty(): print(1)
        else: print(0)