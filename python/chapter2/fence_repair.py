"""
大きな板からN個の板を切り出す。
それらの長さはL_1, L_2, ..., L_Nであり、元の板はそれらの板の長さの合計となる。
板を切る時はその長さ分コストがかかる。
全ての板を切り出すのに、最小のコストはいくつか

3
8 5 8
=>34
"""

n = int(input())
L = list(map(int, input().split()))

def greedy():
    """
    最小の板同士を切るという操作を繰り返す

    Returns
    ----------
    ans : int
        最小のコスト
    """
    ans = 0

    # 板が１本になるまで
    while len(L) > 1:
        L.sort()
        min1 = min(L)
        L.pop(0)
        min2 = min(L)
        L.pop(0)
        ans += min1 + min2
        L.append(min1 + min2)

    return ans

ans = greedy()
print(ans)
