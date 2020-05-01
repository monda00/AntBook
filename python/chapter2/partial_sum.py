"""
整数a_1,...,a_nが与えられる。
その中からいくつか選び、その和をちょうどkにすることができるか判定する。

4
1 2 4 7
13
->Yes

4
1 2 4 7
15
->No
"""

n = int(input())
a_li = list(map(int, input().split()))
k = int(input())

def dfs(i, sum):
    """
    深さ優先探索でiまでのsumを計算し、残りを調べる。

    Parameters
    ----------
    i : int
        リストの添字
    sum : int
        ここまでの合計

    Returns
    ---------
    result : bool
        部分和と等しいか
    """
    # nまで使う・使わないを決めたら判定
    if (i == n):
        return sum == k

    # a[i]を使わない（足さない）
    if (dfs(i+1, sum)):
        return True

    # a[i]を使う（足す）
    if (dfs(i+1, sum+a_li[i])):
        return True

    return False

if (dfs(0, 0)):
    print('Yes')
else:
    print('No')
