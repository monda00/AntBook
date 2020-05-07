"""
1円玉、5円玉、10円玉、50円玉、100円玉、500円玉がそれぞれC_1, C_5, C_10, C_50, C_100, C_500枚ある。
できるだけ少ない枚数でA円を払うには、何枚必要か。

3 2 1 3 0 2
620
=>6
"""

def greedy(tot):
    """
    貪欲法で使える硬貨を選んでいく

    Parameters
    ----------
    tot : int
        目標の合計金額

    Returns
    ----------
    ans : int
        最小の効果の枚数
    """
    ans = 0
    coin_v = [500, 100, 50, 10, 5, 1]
    coin_n = [c500, c100, c50, c10, c5, c1]
    for i in range(6):
        c_num = min(int(tot / coin_v[i]), coin_n[i])
        tot -= coin_v[i] * c_num
        ans += c_num

    return ans

c1, c5, c10, c50, c100, c500 = map(int, input().split())
tot = int(input())

ans = greedy(tot)

print(ans)
