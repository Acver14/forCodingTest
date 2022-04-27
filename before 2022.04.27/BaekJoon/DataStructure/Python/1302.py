from sys import stdin
from collections import defaultdict
input = stdin.readline

n = int(input().rstrip())

book = defaultdict(int)
for _ in range(n):
    book[input().rstrip()] += 1
    
book = dict(sorted(book.items()))
print(max(book.keys(), key=(lambda k: book[k])))