#include<bits/stdc++.h>
using namespace std;
void get_arr(unsigned long long seed, int a[], int n);
int WMergeSort(int a[], int l, int r, int h);
int look(int a[], int p, int q);
int main()
{
    unsigned long long seed;
    int n, h;
    cin >> seed >> n >> h;
    int a[n + 1];
    get_arr(seed, a, n);
    cout << WMergeSort(a, 1, n, h);
    return 0;
}

void get_arr(unsigned long long seed, int a[], int n){
    mt19937_64 gen(seed);
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1; i <= n; i++) {
        int u = gen() % (n - i + 1) + i;
        swap(a[u], a[i]);
    }   
}
int WMergeSort(int a[], int l, int r, int h){
    if (l <= r){
        if (h <= 1) return look(a, l, r);
        else{
            int m = (l + r) / 2;
            return (WMergeSort(a, l, m, h - 1) + WMergeSort(a, m + 1, r, h - 1));
        }
    }
    else return 0;
}
int look(int a[], int p, int q){
    int res = 0, Hmax = 0;
    for (int i = p; i <= q; ++i){
        if (Hmax < a[i]){
            Hmax = a[i];
            ++res;
        }
    }
    return res;
}
