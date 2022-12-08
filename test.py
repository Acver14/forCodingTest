import heapq

class node:
    def __init__(self, A, B):
        self.A = A
        self.B = B

    def __lt__(self, other):
        if self.A < other.A:   #오름차순
            return True
        elif self.A == other.A:
            return self.B > other.B  #첫번재 변수가 같으면 두번재 변수로 내림차순
        else:
            return False

    def __str__(self):
        return 'A : {}, B : {}'.format(self.A, self.B)


l = []
heapq.heappush(l, node(1,1))
heapq.heappush(l, node(1,2))

heapq.heappush(l, node(2,1))
heapq.heappush(l, node(2,2))

heapq.heappush(l, node(3,1))
heapq.heappush(l, node(3,2))

heapq.heappush(l, node(4,1))
heapq.heappush(l, node(4,2))

while l:
    print(heapq.heappop(l))