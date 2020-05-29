"""
n個の互いに区別できない品物をm個以下に分割する方法の総数を求め、Mで割った余りを求める。

4
3
10000
=>4
"""

n = int(input())
m = int(input())
M = int(input())

dp = [[0 for j in range(n + 1)] for i in range(m + 1)]

def dynamic_programming():
    """
    動的計画法で分割の総数を計算する
    dp[i][j] : jのi分割の総数
    """
    dp[0][0] = 1
    for i in range(1, m+1):
        for j in range(n+1):
            if j - i >= 0:
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M
            else:
                dp[i][j] = dp[i - 1][j]

dynamic_programming()
print(dp[m][n])
