from sys import stdin

n, m = map(int, stdin.readline().strip().split())

dictionary = {}
for i in range(n):
    poke = stdin.readline().strip()
    dictionary[str(i+1)] = poke
    dictionary[poke] = str(i+1)

for i in range(m):
    quest = stdin.readline().strip()
    print(dictionary[quest])