"""
大きな板からN個の板を切り出す。
それらの長さはL_1, L_2, ..., L_Nであり、元の板はそれらの板の長さの合計となる。
板を切る時はその長さ分コストがかかる。
全ての板を切り出すのに、最小のコストはいくつか

3
8 5 8
=>34
"""
import queue

n = int(input())
L = list(map(int, input().split()))

def solve_que():
    """
    順位キューを使って解く。

    Returns
    ----------
    ans : int
        最小のコスト
    """
    ans = 0
    que = queue.PriorityQueue()
    for l in L:
        que.put(l)

    while que.qsize() > 1:
        l1 = que.get()
        l2 = que.get()
        ans += l1 + l2
        que.put(l1+l2)

    return ans

ans = solve_que()
print(ans)
