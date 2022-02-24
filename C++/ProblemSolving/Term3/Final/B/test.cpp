// bug here
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = acos(-1.0);
struct Complex {
  double x, y;
  Complex(double _x = 0.0, double _y = 0.0) {
    x = _x;
    y = _y;
  }
  Complex operator-(const Complex &b) const {
    return Complex(x - b.x, y - b.y);
  }
  Complex operator+(const Complex &b) const {
    return Complex(x + b.x, y + b.y);
  }
  Complex operator*(const Complex &b) const {
    return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
  }
};
/*
 * 进行 FFT 和 IFFT 前的反置变换
 * 位置 i 和 i 的二进制反转后的位置互换
 *len 必须为 2 的幂
 */
void change(Complex y[], int len) {
  int i, j, k;
  for (int i = 1, j = len / 2; i < len - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    // 交换互为小标反转的元素，i<j 保证交换一次
    // i 做正常的 + 1，j 做反转类型的 + 1，始终保持 i 和 j 是反转的
    k = len / 2;
    while (j >= k) {
      j = j - k;
      k = k / 2;
    }
    if (j < k) j += k;
  }
}
/*
 * 做 FFT
 *len 必须是 2^k 形式
 *on == 1 时是 DFT，on == -1 时是 IDFT
 */
void fft(Complex y[], int len, int on) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 1) {
    Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));
    for (int j = 0; j < len; j += h) {
      Complex w(1, 0);
      for (int k = j; k < j + h / 2; k++) {
        Complex u = y[k];
        Complex t = w * y[k + h / 2];
        y[k] = u + t;
        y[k + h / 2] = u - t;
        w = w * wn;
      }
    }
  }
  if (on == -1) {
    for (int i = 0; i < len; i++) {
      y[i].x /= len;
    }
  }
}

#define maxn 40005
#define maxs 60005 // to be modify
ll a[maxn];
ll cnt[maxs];
ll cnt2[maxs];
ll ans[maxs];
ll n, S, real_part;
void solve_100(){
    for (int i = 1; i <= 100; ++i){
        for (int j = i + 1; j <= 100; ++j){
            for (int k = j + 1; k <= 100; ++k){
                if (i + j + k <= S)
                    ans[i + j + k] += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    
    for (int i = 1; i * 3 <= S; ++i){
        ans[i * 3] += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
    }

    for (int i = 1; i <= 100; ++i){
        for (int j = 1; j <= 100; ++j){
            if (i != j && 2 * i + j <= S)
                ans[2 * i + j] += cnt[i] * (cnt[i] - 1) / 2 * cnt[j];
        }
    }
}

int main(){
    cin >> n >> S;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] < maxs)
            cnt[a[i]]++;
        if (2 * a[i] < maxs)
            cnt2[2 * a[i]]++;
    }

    if (S <= 100){
        solve_100();
        for (int i = 1; i <= S; ++i)
        cout << ans[i] << " ";
    }
    else {

    ll max_len = 3 * (maxs + 1); ll bit_num = 0;
    while (max_len) {max_len >>= 1; bit_num++;}
    max_len = 1 << bit_num; // set max_len to power of 2
    Complex A[max_len], B[max_len];
    for (int i = 0; i < max_len; ++i){
        A[i] = B[i] = Complex(0, 0);
    }// B not used
    for (int i = 1; i < maxs; ++i){
        A[i].x = cnt[i];
    }
    fft(A, max_len, 1);
    for (int i = 0; i < max_len; ++i){
        A[i] = A[i] * A[i] * A[i];
    }
    fft(A, max_len, -1);
    for (int i = 1; i < maxs; ++i)
        ans[i] += round(A[i].x);

    
    // -2
    for (int i = 1; i <= n; ++i){
        ll ijk = 3 * a[i];
        if (ijk < maxs)
            ans[ijk] += 2;
    }
    
    //+3
    for (int i = 0; i < max_len; ++i){
        A[i] = B[i] = Complex(0, 0);
    }
    for (int i = 1; i < maxs; ++i){
        A[i].x = cnt2[i];
        B[i].x = cnt[i];
    }
    fft(A, max_len, 1);
    fft(B, max_len, 1);
    for (int i = 0; i < max_len; ++i)
        A[i] = A[i] * B[i];
    fft(A, max_len, -1);
    for (int i = 1; i < maxs; ++i)
        ans[i] -= 3 * round(A[i].x);
    

    for (int i = 1; i <= S; ++i)
        cout << ans[i] / 6 << " ";
    }
    
}