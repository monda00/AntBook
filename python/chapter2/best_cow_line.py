"""
N文字の文字列Sが与えられ、N文字の文字列Tを作る。
Tは初めは長さ0の文字列。
以下の操作ができる。
- Sの先頭を1文字削除し、Tの末尾に追加
- Sの末尾を1文字削除し、Tの末尾に追加
辞書順でできるだけ小さいTを作る。

6
ACDBCB
=>ABCBCD
"""

n = int(input())
s = list(input())

def greedy():
    """
    貪欲法でSの先頭と末尾で辞書順として小さい方をTに追加していく。
    同じ場合はさらに次を確認する。

    Returns
    ----------
    t : string
        可能な仕事の数
    """
    t = list()
    while(len(s) > 0):
        for i in range(len(s)):
            if s[0 + i] < s[-1 + i] or len(s) == 1:
                t.append(s[0])
                s.pop(0)
                break
            if s[0 + i] > s[-1 + i]:
                t.append(s[-1])
                s.pop(-1)
                break

    return ''.join(t)

t = greedy()
print(t)
