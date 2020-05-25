"""
整数a_1,...,a_nがそれぞれm_i個ずつ与えられる。
その中からいくつか選び、その和をちょうどkにすることができるか判定する。

3
17
3 3
5 2
8 2
=>Yes
"""

n = int(input())
K = int(input())

item = list()
for _ in range(n):
    item.append(list(map(int, input().split())))

dp = [-1 for j in range(K+1)]

def dynamic_programming():
    """
    動的計画法で個数制限つき部分和問題を解く。
    dp[i+1][j] : i番目まででjを作る際に余る最大のi番目の個数
    """
    dp[0]= 0
    for i in range(n):
        for j in range(K+1):
            if dp[j] >= 0:
                dp[j] = item[i][1]
            elif j < item[i][0] or dp[j - item[i][0]] <= 0:
                dp[j] = -1
            else:
                dp[j] = dp[j - item[i][0]] - 1

dynamic_programming()
if dp[K] >= 0:
    print('Yes')
else:
    print('No')
