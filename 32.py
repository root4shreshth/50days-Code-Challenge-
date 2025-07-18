n, m = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * m for _ in range(n)]
for i in range(n):
    dp[i][m - 1] = mat[i][m - 1]
for j in range(m - 2, -1, -1):
    for i in range(n):        
        right = dp[i][j + 1]
        right_up = dp[i - 1][j + 1] if i > 0 else 0
        right_down = dp[i + 1][j + 1] if i < n - 1 else 0
        dp[i][j] = mat[i][j] + max(right, right_up, right_down)
result = max(dp[i][0] for i in range(n))
print(result)
