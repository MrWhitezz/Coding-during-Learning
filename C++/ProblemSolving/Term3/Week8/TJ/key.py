def mono_key(arr, key):
    for s in arr:
        for ch in s:
            if (ord(ch) == ord(' ')):
                print(' ', end='')
                continue
            shift = ord(ch) - ord('A')
            shift = (shift + key) % 26
            if (ord(ch) == ord('V')):
                shift = ord('E') - ord('A')
            elif(ord(ch) == ord('E')):
                shift = ord('X') - ord('A')
            elif(ord(ch) == ord('K')):
                shift = ord('R') - ord('A')
            # shift %= 26 

            ch = chr(ord('a') + shift)
            print(ch, end='')
    print("")

def try_mono(arr):
    for key in range(1, 26):
        print("key = ", key)
        mono_key(arr, key)