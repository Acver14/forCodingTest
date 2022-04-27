from collections import defaultdict
from sys import stdin
input = stdin.readline

trees = defaultdict(int)
n = 0
while True:
    tree = input().rstrip()
    if not tree:
        break
    trees[tree] += 1
    n += 1

tree_list = list(trees.keys())
tree_list.sort()

for tree in tree_list:
    print('%s %.4f' %(tree, trees[tree]/n*100))