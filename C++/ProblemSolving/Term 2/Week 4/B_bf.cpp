#include <bits/stdc++.h>
using namespace std;
int read()
{
    int f = 1, x = 0; char ch;
    do {ch = getchar(); if (ch == '-') f = -1;} while (ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
    return f * x;
}
int N, T;
bool test();
bool test_bf();
void read_mtx(vector<vector<int>> & M);
void print_mtx(const vector<vector<int>> & M);
void print_vec(const vector<int> &v);
void ran_vec(vector<int> &v, int s);
vector<int> mtpl(const vector<vector<int>> &M, const vector<int> &v);
vector<vector<int>> mtpl_mtx(const vector<vector<int>> &A, const vector<vector<int>> &B);
bool vec_cmp(const vector<int> v1, const vector<int> v2);
bool mtx_cmp(const vector<vector<int>> &A, const vector<vector<int>> &B);
void test_T();
int main()
{
    cin >> T;
    // vector<int> v(N, 0), w(N, 0);
    // ran_vec(v);
    // for (int i = 0; i < N * N; ++i)
    // ;
    // ran_vec(w);
    // print_vec(v);
    // print_vec(w);
    test_T();

    return 0;
}
void test_T(){
    for (int i = 0; i < T; ++i)
        if (test()) cout << "true" << endl;
        else cout << "false" << endl;
}
bool test_bf(){
    vector<vector<int>> A, B, C; 
    read_mtx(A); read_mtx(B); read_mtx(C);
    return mtx_cmp(mtpl_mtx(A, B), C);
}
bool test(){
    N = read();
    if (N <= 100) return test_bf();
    vector<vector<int>> A, B, C; 
    read_mtx(A); read_mtx(B); read_mtx(C);
    vector<int> v(N, 0);
    for (int i = 0; i < 65; ++i){
        ran_vec(v, i);
        if (!vec_cmp(mtpl(A, mtpl(B, v)), mtpl(C, v))) return false;
    }
    return true;
}
vector<int> mtpl(const vector<vector<int>> &M, const vector<int> &v){
    vector<int> tmp(v);
    int temp = 0;
    for (int i = 0; i < N; ++i){
        temp = 0;
        for (int j = 0; j < N; ++j)
            temp += M[i][j] * v[j];
        tmp[i] = temp;
    }
    return tmp;
}
vector<vector<int>> mtpl_mtx(const vector<vector<int>> &A, const vector<vector<int>> &B){
    vector<vector<int>> res(A);
    int temp = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j){
            temp = 0;
            for (int k = 0; k < N; ++k)
                temp += A[i][k] * B[k][j];
            res[i][j] = temp;
        }
    return res;
}
bool vec_cmp(const vector<int> v1, const vector<int> v2){
    for (int i = 0; i < N; ++i)
        if (v1[i] != v2[i]) return false;
    return true;
}
bool mtx_cmp(const vector<vector<int>> &A, const vector<vector<int>> &B){
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (A[i][j] != B[i][j]) return false;
    return true;
}
void read_mtx(vector<vector<int>> & M){
    vector<int> tmp;
    for (int i = 0; i < N; ++i){
        tmp.clear();
        for (int j = 0; j < N; ++j)
            tmp.push_back(read());
        M.push_back(tmp);
    }
}
void ran_vec(vector<int> &v, int s){
    srand((unsigned)time(NULL) + s);// it is not totally random
    for (int i = 0; i < N; ++i)
        v[i] = rand() % 2;
}
void print_mtx(const vector<vector<int>> & M){
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j)
            cout << M[i][j] << " ";
        cout << endl;
    }
}
void print_vec(const vector<int> &v){
    for (int i = 0; i < N; ++i)
        cout << v[i] << " ";
    cout << endl;
}
