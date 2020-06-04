"""
トラックで距離Lを移動する。はじめにガソリンがP積まれている。
距離１移動するごとにガソリン１消費する。
途中にはガソリンスタンドがN個あり、i番目のガソリンスタンドはスタートから距離A_iにあり、B_iだけガソリンを補給できる。
最小で何回の補給で移動できるか。移動できない場合は-1を出力する。

4
25
10
10 10
14 5
20 2
21 4
=>2
"""
import queue

n = int(input())
l = int(input())
p = int(input())
g_li = list()

for _ in range(n):
    g_li.append(list(map(int, input().split())))

def solve():
    """
    ガソリンが0になったタイミングで追加した中から
    もっともガソリンの補給量が多いところから補給する

    Returns
    ----------
    ans : int
        最小の補給回数
    """
    que = queue.PriorityQueue()
    ans = 0
    pos = 0
    tank = p

    for i in range(n):
        next_d = g_li[i][0] - pos
        while tank - next_d < 0:
            if (que.empty()):
                print(-1)
                exit()
            tank += que.get()
            ans += 1
        tank -= next_d
        pos = g_li[i][0]
        que.put(g_li[i][1])

    return ans


ans = solve()
print(ans)
