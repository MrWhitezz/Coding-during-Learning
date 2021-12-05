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

def Binary_GCD(a, b):
    if (a < b):
        return Binary_GCD(b, a)
    if (b == 0):
        return a
    if (a % 2 == 0 and b % 2 == 0):
        return 2 * Binary_GCD(a // 2, b // 2)
    elif (a % 2 == 1 and b % 2 == 1):
        return Binary_GCD((a - b) // 2, b)
    elif (a % 2 == 1 and b % 2 == 0):
        return Binary_GCD(a, b // 2)
    else:
        return Binary_GCD(a // 2, b)