"""
N個の点が直線上にある。
点iの位置はx_iである。
N個の点から選び、その点から距離R以内にN個の点全てが存在するようにする。
選択した点をできるだけ小さくするといくつになるか。

6
10
1 7 15 20 30 50
=>3
"""

n = int(input())
r = int(input())
x_li = list(map(int, input().split()))

def greedy():
    """
    左端の点からRの範囲内で最も遠い点を選択する。
    残りもその点からRの範囲内で最も遠い点を選択していく。

    Returns
    ----------
    ans : int
        選択した点の数
    """
    ans = 0
    i = 0
    while(i < n):
        # sはカバーされてない左端の点
        s = x_li[i]
        i += 1
        # sから距離Rを超える点まで
        while(i < n and x_li[i] <= s + r):
            i += 1
        # pは新しく選択する点
        p = x_li[i - 1]
        # pから距離Rを超える点まで
        while(i < n and x_li[i] <= p + r):
            i += 1

        ans += 1

    return ans

ans = greedy()
print(ans)
