"""
重さと価値がw_iとv_iであるn個の品物がある。
それらを重さの総和がWを超えないように、価値を最大化させる。

4
5
2 3
1 2
3 4
2 2
=>7
"""

n = int(input())
W = int(input())
item = list()
for _ in range(n):
    # item[0]:重み
    # item[1]:価値
    item.append(list(map(int, input().split())))

dp = [[0 for j in range(W + 1)] for i in range(n + 1)]

def dynamic_programming():
    """
    動的計画法でナップサックを解く。
    d[i+1][j] : i番目までの品物から重さの総和がj以下になるときの価値の最大値
    """
    for i in range(n):
        for j in range(W+1):
            if(j < item[i][0]):
                dp[i + 1][j] = dp[i][j]
            else:
                dp[i + 1][j] = max(dp[i][j], dp[i][j - item[i][0]] + item[i][1])

dynamic_programming()
print(dp)
print(dp[n][W])
