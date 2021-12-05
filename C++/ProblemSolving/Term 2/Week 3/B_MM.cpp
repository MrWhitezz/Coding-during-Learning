#include<bits/stdc++.h>
using namespace std;
void print_a(int a[], int n);
void get_arr(unsigned long long seed, int a[], int n);
void WMergeSort(int a[], int l, int r, int h);
int look(int a[], int n);
void test(unsigned long long seed, int n, int h, int a[]);
vector<int> Div;
void div(int l, int r, int h);
void Merge(int a[], int p, int q, int r);
void MMergeSort(int a[]);
vector<int> MMSort(vector<vector<int>> &V);
vector<int> MERGE(vector<int> &v1, vector<int> &v2);
int n, h;
int main()
{
    unsigned long long seed;
    cin >> seed >> n >> h;
    int a[n + 1];
    get_arr(seed, a, n);
    div(1, n, h);

    sort(Div.begin(), Div.end());
    auto it_e = unique(Div.begin(), Div.end());
    Div.erase(it_e, Div.end());

    MMergeSort(a);
    //print_a(a, n);
    cout << look(a, n);
    //test(seed, n, h, a);
}
vector<int> MMSort(vector<vector<int>> &V){
    if (V.size() == 1) return V[0];
    vector<vector<int>> tmp;
    auto it = V.begin();
    for (; it != V.end() && (it + 1) != V.end(); it += 2){
        tmp.push_back(MERGE(*it, *(it + 1)));
    }
    if ((it + 1) == V.end()) tmp.push_back(*it);
    V.swap(tmp);
    tmp.clear();
    return MMSort(V);
}
vector<int> MERGE(vector<int> &v1, vector<int> &v2){
    vector<int> tmp;
    auto it1 = v1.begin(), it2 = v2.begin();
    while (it1 != v1.end() && it2 != v2.end()){
        if (*it1 < *it2) tmp.push_back(*it1++);
        else tmp.push_back(*it2++);
    }
    while (it1 != v1.end()) tmp.push_back(*it1++);
    while (it2 != v2.end()) tmp.push_back(*it2++);
    return tmp;
}
void MMergeSort(int a[]){
    // asumming Div.size() > 0, Div[0] != 1
    vector<vector<int>> V;
    vector<int> v;
    for (int i = 1; i <= *Div.begin(); ++i)
        v.push_back(a[i]);
    V.push_back(v);
    auto it = Div.begin();
    for (; (it + 1) != Div.end(); ++it){
        v.clear();
        for (int j = *it + 1; j <= *(it + 1); ++j)
            v.push_back(a[j]);
        V.push_back(v);
    }
    v.clear();
    for (int j = *it + 1; j <= n; ++j)
        v.push_back(a[j]);
    V.push_back(v);

    vector<int> res = MMSort(V);
    for (int i = 0; i < n; ++i)
        a[i + 1] = res[i];
    return;
}
void div(int l, int r, int h){
    if (l <= r){
        if (h <= 1) return;
    else {
        int m = (l + r) / 2;
        Div.push_back(m);
        div(l, m, h - 1);
        div(m + 1, r, h - 1);
        }
    }
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
            Merge(a, l, m, r);
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
void Merge(int a[], int p, int q, int r){
    int pl = p, pr = q + 1, pb = 0;
    int b[r - p + 1];  
    while (pl <= q && pr <= r){
        if (a[pl] < a[pr]) b[pb++] = a[pl++];
        else b[pb++] = a[pr++];
    }
    if (pl <= q)
        for (int i = pl; i <= q; ++i)
            b[pb++] = a[i];
    if (pr <= r)
        for (int i = pr; i <= r; ++i)
            b[pb++] = a[i];
    for (int i = 0; i < r - p + 1; ++i)
        a[p + i] = b[i];
}