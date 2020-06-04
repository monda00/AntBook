"""
n個の品物があり、i番目の品物はa_i個ある。
同じ品物は区別できない。
これらの品物の中からm個選ぶ組み合わせの総数を求め、Mで割った余りを求める。

3
3
1 2 3
10000
=>6
"""

n = int(input())
m = int(input())
a = list(map(int, input().split()))
M = int(input())

dp = [[0 for j in range(n + 1)] for i in range(m + 1)]

def dynamic_programming():
    """
    動的計画法で重複組み合わせを解く
    dp[i][j]: i番目までの品物からj個選ぶ組み合わせの総数
    """
    for i in range(n+1):
        dp[i][0] = 1

    for i in range(n):
        for j in range(m+1):
            if j - 1 - a[i] >= 0:
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M
            else:
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M

dynamic_programming()
print(dp[n][m])
