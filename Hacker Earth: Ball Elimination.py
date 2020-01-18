inf = (1 << 30)


def solve(i, j):
    if dp[i][j] is not None:
        return dp[i][j]
    if i == j:
        res = 1
    elif i > j:
        res = 0
    else:
        res = inf
        if ar[i] == ar[j]:
            res = solve(i+1, j-1)
        else:
            for k in range(i, j):
                res = min(res, solve(i, k) + solve(k+1, j))
    dp[i][j] = res
    return dp[i][j]


n = int(input())
ar = [int(i) for i in input().split()]      # array
dp = [[None]*n for i in range(n)]           # 2D array
ans = solve(0, n-1)
print(ans)
