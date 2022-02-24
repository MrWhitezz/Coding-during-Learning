def dist(a, b):
    assert(len(a) == len(b))
    ans = 0
    for i in range(0, len(a)):
        if (a[i] != b[i]):
            ans += 1
    return ans

def codes_dist(arr):
    ans = 10000
    for i in range(0, len(arr)):
        for j in range(i + 1, len(arr)):
            ans = min(ans, dist(arr[i], arr[j]))
    return ans
