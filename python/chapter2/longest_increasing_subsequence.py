"""
長さnの数列a_0, ..., a_n-1がある。
数列の増加部分列のうち、最長のものの長さを求める。

5
4 2 3 1 5
=> 3
"""

INF = 99999999
n = int(input())
a = list(map(int, input().split()))

dp = [INF for i in range(n)]

def dynamic_programming():
    """
    動的計画法で最長増加部分列問題を解く。
    dp[i] : 最後がa_iであるような最長の増加部分列の長さ

    Returns
    ----------
    ans : int
        増加部分列の最長値
    """
    ans = 0
    for i in range(n):
        dp[i] = 1
        for j in range(i):
            if a[j] < a[i]:
                dp[i] = max(dp[i], dp[j]+1)
        ans = max(ans, dp[i])

    return ans

ans = dynamic_programming()
print(ans)
