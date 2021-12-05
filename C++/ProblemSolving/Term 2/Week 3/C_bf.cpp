#include<bits/stdc++.h>
using namespace std;
struct subarr
{
friend bool operator== (const subarr &s1, const subarr &s2);
    int beg;
    int end;
    int sum;
};
inline bool
operator== (const subarr &s1, const subarr &s2){
    return s1.beg == s2.beg && s1.end == s2.end && s1.sum == s2.sum;
}
bool cmp (const subarr &s1, const subarr &s2);
subarr minsub(int k, const subarr dp []);
subarr minsub_bf(int k, int a[]);
int n, k;
int main()
{
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    subarr dp[n + 1];
    dp[1].beg = dp[1].end = 1;
    dp[1].sum = a[1];
    for (int i = 2; i <= n; ++i){
        dp[i].end = i;
        dp[i].sum = dp[i - 1].sum > 0 ? dp[i - 1].sum + a[i] : a[i];
        dp[i].beg = dp[i - 1].sum > 0 ? dp[i - 1].beg : i;
    }
    subarr res;
    res = minsub_bf(k, a);
    cout << res.beg <<  " " << res.end << endl;
    return 0;
}
// bool cmp (const subarr &s1, const subarr &s2){
//     if (s1.sum == s2.sum){
//         if (s1.beg == s1.beg)
//             {return s1.end > s2.end;}
//         else {return s1.beg > s2.beg;}
//     }
//     else return s1.sum < s2.sum;
// }
bool cmp (const subarr &s1, const subarr &s2){
    if (s1.sum == s2.sum && s1.beg == s2.beg)
        return s1.end > s2.end;
    else if (s1.sum == s2.sum)
        return s1.beg > s2.beg;
    else 
        return s1.sum < s2.sum;
}
subarr minsub_bf(int k, int a[]){
    subarr tmp;
    vector<subarr> v;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j){
            tmp.beg = i;
            tmp.end = j;
            int st = 0;
            for (int k = i; k <= j; ++k)
                st += a[k];
            tmp.sum = st;
            v.push_back(tmp);
        }
    sort(v.begin(), v.end(), cmp);
    return v[v.size() - k];
}
subarr minsub(int k, const subarr dp[]){
    vector<subarr> v, dp_cp;
    for (int i = 1; i <= n; ++i)
        dp_cp.push_back(dp[i]);
    sort(dp_cp.begin(), dp_cp.end(), cmp);
    
    for (int i = 0; i < k; ++i){
        //int cnt = k - 1 - i;
        subarr tmp = dp_cp[dp_cp.size() - i - 1];
        v.push_back(tmp);
        while (tmp.beg != 1){
            tmp.sum = tmp.sum + dp[tmp.beg - 1].sum;
            tmp.beg = dp[tmp.beg - 1].beg;
            v.push_back(tmp);
            //--cnt;
        }
    }
    // test
    // cout << dp_cp[n].beg << " " << dp_cp[n].end << dp_cp[n].sum << endl;
    sort(v.begin(), v.end(), cmp);
    unique(v.begin(), v.end());
    return v[v.size() - k];
}