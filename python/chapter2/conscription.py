"""
N人の女とM人の男を徴兵する。
一人当たり10000ドルかかるが、親しい人がすでに徴兵されている場合は10000-親密度の費用になる。
適切な順番で徴兵した時の最小の費用を求める。

5
5
8
4 3 6831
1 3 4583
0 0 6592
0 1 3063
3 3 4975
1 3 2049
4 2 2104
2 2 781
=>71071
"""
from kruskal import Kruskal_UnionFind

N = int(input())
M = int(input())
R = int(input())

uf = Kruskal_UnionFind(N+M)
for _ in range(R):
    u, v, d = map(int, input().split())
    uf.add(u, v+N, -d)

ans = uf.Kruskal() + 10000 * (N + M)
print(ans)
