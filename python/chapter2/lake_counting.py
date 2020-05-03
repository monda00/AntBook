"""
N＊Mの庭に、水たまりができた。
水たまりは８近傍で隣接している。
全部で幾つの水たまりがあるか。

10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
->3
"""

def dfs(x, y):
    """
    深さ優先探索で(x,y)から'W'を探して'.'に置き換えられるまで繰り返す。

    Parameters
    ----------
    x : int
        現在位置x座標
    y : int
        現在位置y座標
    """
    field[i][j] = '.'

    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            nx = x + dx
            ny = y + dy
            if 0 <= nx < n and 0 <= ny < m and field[nx][ny] == 'W':
                dfs(nx, ny)

n, m = map(int, input().split())
field = list()
for _ in range(n):
    field.append(list(input()))

lake_num = 0
for i in range(n):
    for j in range(m):
        if (field[i][j] == 'W'):
            dfs(i, j)
            lake_num += 1

print(lake_num)
