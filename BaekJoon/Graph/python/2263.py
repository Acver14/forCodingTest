from sys import stdin
input = stdin.readline

def post_in_to_pre(post_list, in_list):
    if post_list:
        root = post_list[-1]
        print(in_list)
        mid = in_list.index(root)
        print(root, end=" ")
        post_in_to_pre(post_list[1:mid + 1], in_list[:mid])
        post_in_to_pre(post_list[mid + 1:], in_list[mid + 1:])
        
n = int(input())
in_order = list(map(int, input().rstrip().split()))
post_order = list(map(int, input().rstrip().split()))
post_in_to_pre(post_order, in_order)