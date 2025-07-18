n = int(input())
arr = list(map(int, input().split()))
max_sum = 0
for i in range(n - 1):
    a, b = arr[i], arr[i + 1]
    pair_sum = a + b
    max_sum = max(max_sum, pair_sum)
print(max_sum)
