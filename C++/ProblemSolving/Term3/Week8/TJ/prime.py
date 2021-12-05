import math
def prime_N(n):
    arr = [i for i in range(2, n + 1)]
    old_p, p, index = 1, 1, 0
    while(p <= math.sqrt(n)):
        p = arr[index]
        if (p == old_p):
            index += 1
            p = arr[index]
        old_p = p
        for j in range(2, n // p + 1):
            rem = j * p
            if rem in arr:
                arr.remove(rem)
    return arr


def relative_prime(N):
    prime_list = prime_N(N)
    arr = [i for i in range(1, N)]
    for p in prime_list:
        if N % p == 0:
            for j in range(1, N // p + 1):
                rem = j * p
                if rem in arr:
                    arr.remove(rem)
    return arr
    
def is_prime(x):
    for i in range(2, round(math.sqrt(x))):
        if (x % i == 0):
            return False
    return True