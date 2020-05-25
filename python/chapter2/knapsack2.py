"""
重さと価値がw_iとv_iであるn個の品物がある。
それらを重さの総和がWを超えないように、価値を最大化させる。
重さの制約が大きい。

4
5
2 3
1 2
3 4
2 2
=>7
"""

INF = 9999999
n = int(input())
W = int(input())
item = list()
for _ in range(n):
    # item[0]:重み
    # item[1]:価値
    item.append(list(map(int, input().split())))

dp = [[INF for j in range(10000 + 1)] for i in range(n + 1)]

def dynamic_programming():
    """
    動的計画法でナップサックを解く。
    d[i+1][j] : i番目までの品物から価値の総和がjになるときの重さの最小値
    """
    dp[0][0] = 0
    for i in range(n):
        for j in range(10001):
            if(j < item[i][1]):
                dp[i + 1][j] = dp[i][j]
            else:
                dp[i + 1][j] = min(dp[i][j], dp[i][j - item[i][1]] + item[i][0])

dynamic_programming()

for i in range(10001):
    if dp[n][i] <= W:
        ans = i
print(ans)
