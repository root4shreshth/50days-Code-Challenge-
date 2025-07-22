import math
def is_valid(piles, k, x):
    time = 0
    for b in piles:
        time += math.ceil(b / x)
    return time <= k
def find_min_speed(arr, k):
    l = 1
    r = max(arr)
    ans = r
    while l <= r:
        m = (l + r) // 2
        if is_valid(arr, k, m):
            ans = m
            r = m - 1
        else:
            l = m + 1
    return ans
arr = list(map(int, input().split()))
k = int(input())
print(find_min_speed(arr, k))
