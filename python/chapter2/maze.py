"""
N*Mの上下左右に移動可能な迷路の最短経路を求める。

10 10
0 1
9 8
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
->22
"""
import queue
INF = 100000000

n, m = map(int, input().split())
sx, sy = map(int, input().split())
gx, gy = map(int, input().split())
maze = list()
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for _ in range(n):
    maze.append(list(input()))

def bfs():
    """
    幅優先探索で迷路の最短経路を計算する。

    Returns
    ----------
    ans : int
        迷路の最短経路
    """
    que = queue.Queue()
    d = [[INF] * m for i in range(n)]
    que.put([sx, sy])
    d[sx][sy] = 0

    while not que.empty():
        p = que.get()
        if p[0] == gx and p[1] == gy:
            break
        for i in range(4):
            nx = p[0] + dx[i]
            ny = p[1] + dy[i]
            if 0 <= nx < n and 0 <= ny < m and maze[nx][ny] != '#' and d[nx][ny] == INF:
                que.put([nx, ny])
                d[nx][ny] = d[p[0]][p[1]] + 1
    return d[gx][gy]

ans = bfs()
print(ans)
