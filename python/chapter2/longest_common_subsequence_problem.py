"""
二つの文字列s_1,...s_nとt_1,...,t_mが与えられる。
2つの共通部分文字列の長さの最大値を求める。

4
4
abcd
becd
=>3
"""

n = int(input())
m = int(input())
s = list(input())
t = list(input())

dp = [[0 for j in range(m + 1)] for i in range(n + 1)]

def dynamic_programming():
    """
    動的計画法で最長共通部分問題を解く
    dp[i][j]: s_1...s_iとt_1...t_jに対する共通部分の長さ
    """
    for i in range(n):
        for j in range(m):
            if s[i] == t[j]:
                dp[i + 1][j + 1] = dp[i][j] + 1
            else:
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1])

dynamic_programming()
print(dp[n][m])
