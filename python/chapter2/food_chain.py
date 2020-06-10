"""
N匹の動物がいて、A、B、Cの3種類である。
AはBを、BはCを、CはAを食べる。
2種類のデータが与えられる。
タイプ１：xとyは同じ種類
タイプ２：xはyを食べる
与えられた情報のうち誤っているのはいくつか。

100
7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
=>3
"""
from unionfind import UnionFind

n = int(input())
k = int(input())

data = []
for _ in range(k):
    data.append(list(map(int, input().split())))

# x, x+n, x+2nをそれぞれx-A, x-B, x-Cの要素とする
uf = UnionFind(n*3)

ans = 0
for d in data:
    typ = d[0]
    x = d[1] - 1
    y = d[2] - 1

    if x < 0 or x >= n or y < 0 or y >= n:
        ans += 1
        continue

    if typ == 1:
        if uf.isSameGroup(x, y+n) or uf.isSameGroup(x, y+2*n):
            ans += 1
        else:
            uf.Unite(x, y)
            uf.Unite(x+n, y+n)
            uf.Unite(x+2*n, y+2*n)
    else:
        if uf.isSameGroup(x, y) or uf.isSameGroup(x, y+2*n):
            ans += 1
        else:
            uf.Unite(x, y)
            uf.Unite(x+n, y+n)
            uf.Unite(x+2*n, y+2*n)

print(ans)
