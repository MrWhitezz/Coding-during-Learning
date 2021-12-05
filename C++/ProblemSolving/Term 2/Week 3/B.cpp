#include<bits/stdc++.h>
using namespace std;
void print_a(int a[], int n);
void get_arr(unsigned long long seed, int a[], int n);
void WMergeSort(int a[], int l, int r, int h);
int look(int a[], int n);
void test(unsigned long long seed, int n, int h, int a[]);
int get_log(int n);
int main()
{
    unsigned long long seed;
    int n, h;
    cin >> seed >> n >> h;
    int a[n + 1];
    get_arr(seed, a, n);
    if (h >= get_log(n)){
        cout << n;
        return 0;
    }
    WMergeSort(a, 1, n, h);
    cout << look(a, n);

    //print_a(a, n);
    //test(seed, n, h, a);
}
int get_log(int n){
    int res = 1;
    while (n){
        n = (n == 1 ? 0 : (n + 1) / 2);
        res++;
    }
    return res;
}
void print_a(int a[], int n){
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    //cout << endl;
}
void get_arr(unsigned long long seed, int a[], int n){
    mt19937_64 gen(seed);
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1; i <= n; i++) {
        int u = gen() % (n - i + 1) + i;
        swap(a[u], a[i]);
    }   
}
void WMergeSort(int a[], int l, int r, int h){
    if (l < r){
        if (h <= 1) return;
        else{
            int m = (l + r) / 2;
            WMergeSort(a, l, m, h - 1);
            WMergeSort(a, m + 1, r, h - 1);
            int b[r - l + 1];
            int pl = l, pr = m + 1, pb = 0;
            while (pl <= m && pr <= r){
                if (a[pl] < a[pr]) b[pb++] = a[pl++];
                else b[pb++] = a[pr++];
            }
            if (pl <= m){
                for (int i = pl; i <= m; ++i)
                    b[pb++] = a[i];
            }
            if (pr <= r){
                for (int i = pr; i <= r; ++i)
                    b[pb++] = a[i];
            }
            for (int i = 0; i < r - l + 1; ++i)
                a[l + i] = b[i];
        }
    }
    else return;
}
int look(int a[], int n){
    int res = 0, Hmax = 0;
    for (int i = 1; i <= n; ++i){
        if (Hmax < a[i]){
            Hmax = a[i];
            ++res;
        }
    }
    return res;
}
void test(unsigned long long seed, int n, int h, int a[]){
    for (int i = 0; i < 10; ++i){
        get_arr(seed, a, n);
        WMergeSort(a, 1, n, i);
        cout << "When h = " << i << ", the permutation is ";
        print_a(a, n);
        cout << "Result is " << look(a, n) << endl;
    }
}