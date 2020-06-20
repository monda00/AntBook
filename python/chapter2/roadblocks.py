"""
R本の道とN個の交差点がある。
1番の交差点からN番の交差点への2番目の最短路の長さを求める。

4
4
1 2 100
2 3 250
2 4 200
3 4 100
"""
from heapq import heappush, heappop

INF = 99999999

N = int(input())
R = int(input())
G = [[] for i in range(N)]

for _ in range(R):
    v, w, cost = map(int, input().split())
    G[v-1].append([w-1, cost])
    G[w-1].append([v-1, cost])

dist1 = [INF for i in range(N)]
dist2 = [INF for i in range(N)]

def dijkstra():
    """
    ダイクストラ法を応用して2番目の最短経路を求める
    """

    que = [(0, 0)]

    dist1[0] = 0

    while que:
        s, d = heappop(que)
        if dist2[s] < d:
            continue

        for t, t_cost in G[s]:
            tmp_d = d + t_cost
            if dist1[t] > tmp_d:
                dist1[t], tmp_d = tmp_d, dist1[t]
                heappush(que, (t, dist1[t]))
            if dist2[t] > tmp_d and dist1[t] < tmp_d:
                dist2[t] = tmp_d
                heappush(que, (t, dist2[t]))

dijkstra()
print(dist2[N-1])
