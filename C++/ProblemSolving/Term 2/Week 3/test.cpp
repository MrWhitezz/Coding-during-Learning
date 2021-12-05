#include<bits/stdc++.h>
using namespace std;
struct subarr
{
    int beg;
    int end;
    int sum;
};
bool Mycmp(int a, int b){
    return a < b;
}
bool cmp (const subarr &s1, const subarr &s2){
    if (s1.sum == s2.sum && s1.beg == s2.beg)
        return s1.end > s2.end;
    else if (s1.sum == s2.sum)
        return s1.beg > s2.beg;
    else 
        return s1.sum < s2.sum;
}
int main()
{
    // vector<int> v;
    // for (int i = 0; i < 10; ++i)
    //     v.push_back(i);
    // for (auto it = v.begin(); it != v.end(); ++it)
    //     cout << *it << " ";
    // cout << endl;
    // sort (v.begin(), v.end(), Mycmp);
    // for (auto it = v.begin(); it != v.end(); ++it)
    //     cout << *it << " ";
    // cout << endl;
    subarr tmp;
    vector<subarr> v;
    for (int i = 0; i < 2; ++i){
        cout << "Enter the beg: ";
        cin >> tmp.beg;
        cout << "Enter the end: ";
        cin >> tmp.end;
        cout << "Enter the sum: ";
        cin >> tmp.sum;
        v.push_back(tmp);
    }
    for (auto it = v.begin(); it != v.end(); ++it){
        cout << it->beg << it->end << it->sum << endl;
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it = v.begin(); it != v.end(); ++it){
        cout << it->beg << it->end << it->sum << endl;
    }

    return 0;
}