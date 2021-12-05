#include<bits/stdc++.h>
using namespace std;
void print_a(int a[], int n);
void get_arr(unsigned long long seed, int a[], int n);
int look(int a[], int p, int q);
void test(unsigned long long seed, int n, int h, int a[]);
void div(int l, int r, int h);
int mergeLook(int a[]);
set<int> Div;
int n, h;
int main()
{
    unsigned long long seed;
    cin >> seed >> n >> h;
    int a[n + 1];
    get_arr(seed, a, n);
    div(1, n, h);
    cout << mergeLook(a);

    //print_a(a, n);
    //test(seed, n, h, a);
}
void div(int l, int r, int h){
    if (l <= r){
        if (h <= 1) return;
    else {
        int m = (l + r) / 2;
        Div.insert(m);
        div(l, m, h - 1);
        div(m + 1, r, h - 1);
        }
    }
}
int mergeLook(int a[]){
    if (Div.empty()) return look(a, 1, n);
    int res = 0;
    res += look(a, 1, *Div.begin());
    auto it = Div.begin();
    auto jt = Div.begin();
    jt++;
    for (; jt != Div.end(); ++it, ++jt){
        res += look(a, *it + 1, *jt);
    }
    res += look(a, *it + 1, n);
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
// void test(unsigned long long seed, int n, int h, int a[]){
//     for (int i = 0; i < 10; ++i){
//         get_arr(seed, a, n);
//         WMergeSort(a, 1, n, i);
//         cout << "When h = " << i << ", the permutation is ";
//         print_a(a, n);
//         cout << "Result is " << look(a, n) << endl;
//     }
// }