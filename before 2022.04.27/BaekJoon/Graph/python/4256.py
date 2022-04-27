from sys import stdin
input = stdin.readline
def pre_in_to_post(pre_list, in_list):
    if pre_list:
        root = pre_list[0]
        mid = in_list.index(root)
        pre_in_to_post(pre_list[1:mid + 1], in_list[:mid])
        pre_in_to_post(pre_list[mid + 1:], in_list[mid + 1:])
        print(root, end=" ") # 후위이므로 탐색 끝나고 출력
        
t = int(input())        
for _ in range(t):
    n = int(input())
    pre_order = list(map(int, input().rstrip().split()))
    in_order = list(map(int, input().rstrip().split()))
    pre_in_to_post(pre_order, in_order)
    print()