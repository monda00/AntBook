"""
n個の仕事がある。
各仕事は時間s_iに始まり、時間t_iに終わる。
仕事をする時は、他の仕事と被ってはいけない。
できるだけ多くの仕事をすると、何個の仕事ができるか。

5
1 3
2 5
4 7
6 9
8 10
=>3
"""

n = int(input())
work_li = list()
for _ in range(n):
    work_li.append(list(map(int, input().split())))

def greedy():
    """
    貪欲法で終了時間が最も早いものを繰り返し選択する。

    Returns
    ----------
    ans : int
        可能な仕事の数
    """
    work_li.sort(key=lambda x: x[1])

    ans = 0
    prev_work_end_time = 0
    for work in work_li:
        if prev_work_end_time < work[0]:
            ans += 1
            prev_work_end_time = work[1]

    return ans

ans = greedy()
print(ans)
