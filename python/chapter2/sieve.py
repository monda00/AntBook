"""
エラトステネスのふるい
"""

def sieve(n):
    prime_num = 0
    prime = [0 for i in range(n+1)]
    is_prime = [True for i in range(n+1)]
    is_prime[0] = False
    is_prime[1] = False

    for i in range(2, n+1):
        if is_prime[i]:
            prime_num += 1
            prime[prime_num] = i
            for j in range(2*i, n+1, i):
                is_prime[j] = False

    return prime_num

n = int(input())
print(sieve(n))
