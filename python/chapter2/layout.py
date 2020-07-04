"""
牛がN頭いて、番号順に並んでいる。
仲のいい牛と仲の悪い牛がいて、一定の距離を保ちたいと思っている。
複数の牛が同じ場所に並ぶことも可能。
ML個の仲のいい牛の情報(AL, BL, DL)とMD個の仲の悪い牛の情報(AD, BD, DD)が与えられる。
仲のいい牛は最大距離がDLとなるように、仲の悪い牛は最小距離がDDとなるように並べる。
この制約をみたす並び方のうち、1番の牛とN番の牛の最大距離を求める。
並び方が存在しない場合は-1を、いくつでも作れる場合は-2を出力する。

4
2
1 3 10
2 4 20
1
2 3 3
=>27
"""
INF = 99999999
n = int(input())
ml = int(input())
ML = []
for _ in range(ml):
    ML.append(list(map(int, input().split())))
md = int(input())
MD = []
for _ in range(md):
    MD.append(list(map(int, input().split())))


def bellmanford():
    for k in range(n):
        updated = False
        for i in range(n-1):
           if d[i+1] < INF:
               if d[i] > d[i+1]:
                   d[i] = d[i+1]
                   updated = True
        for al, bl, dl in ML:
            if d[al - 1] < INF:
                if d[bl-1] > d[al-1] + dl:
                    d[bl-1] = d[al-1] + dl
                    updated = True
        for ad, bd, dd in MD:
            if d[bd - 1] < INF:
                if d[ad-1] > d[bd-1] - dd:
                    d[ad-1] = d[bd-1] - dd
                    updated = True
    return updated

d = [0 for i in range(n)]
updated = bellmanford()
if updated:
    print(-1)
    exit()

d = [INF for i in range(n)]
d[0] = 0
bellmanford()
ans = d[n-1]

if ans == INF:
    ans = -2

print(ans)
