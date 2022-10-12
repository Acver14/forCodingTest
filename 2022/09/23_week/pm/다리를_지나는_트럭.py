from collections import deque
def solution(bridge_length, weight, truck_weights):
    bridge = deque([])
    truck_weights = deque(truck_weights)
    T = 0
    while truck_weights or bridge:
        T += 1
        if bridge and T - bridge[0][1] >= bridge_length:
            bridge.popleft()
        if truck_weights:
            if sumBridge(bridge) + truck_weights[0] <= weight:
                bridge.append((truck_weights.popleft(), T))
    return T

def sumBridge(bridge):
    _sum = 0
    for b in bridge:
        _sum += b[0]
    return _sum