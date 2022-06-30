def solution(brown, yellow):
    for col in range(1, brown):
        for row in range(brown-1, 1, -1):
            if col * 2 + row * 2 - 4 == brown:
                if (col-2) * (row-2) == yellow:
                    return [row, col]