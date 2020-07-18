"""
整数a,bの区間内にいくつの素数があるか。

22 37
=>3

22801763489 22801787297
=>1000
"""
import math

a, b = map(int, input().split())

def segment_sieve(a, b):
    is_prime = [True for i in range(b-a)]
    is_prime_small = [True for i in range(int(math.sqrt(b)))]

    for i in range(2, int(math.sqrt(b))):
        if is_prime_small[i]:
            for j in range(2*i, int(math.sqrt(b)), i):
                is_prime_small[j] = False
            for j in range(max(2*i, (a+i-1)//i), b, i):
                is_prime[j-a] = False
    num = sum(x==True for x in is_prime)
    return num

ans = segment_sieve(a, b)
print(ans)
