def fast_pow(x, N, P):
    ans = 1
    while (N > 0):
        if (N & 1):
            ans = ans * x % P
        x = x * x % P
        N >>= 1
    return ans


def encrypt(n, E, x):
    ans = 0
    return fast_pow(x, E, n)
    # else:
    #     return fast_pow(x // 10000, E, n) * 10000 + fast_pow(x % 10000 // 100, E, n) * 100 + fast_pow(x % 100, E, n)
def gcdd(arr, a, b):
    if (a == 0):
        arr[0] = 0
        arr[1] = 1
        return b
    else:
        a1 = b % a
        b1 = a
        q = b // a
        ans = gcdd(arr, a1, b1)
        tmp = arr[1]
        arr[1] = arr[0]
        arr[0] = tmp - q * arr[0]
        return ans

def D_decode(m, E):
    arr = [0, 0]
    gcdd(arr, E, m)
    D = arr[0]
    while(D < 0):
        D += m
    return D