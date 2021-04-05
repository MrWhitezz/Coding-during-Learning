#include<bits/stdc++.h>
using namespace std;
template<typename Seq>
void print(Seq const &s){
    for (const auto i : s)
        cout << i << " ";
    cout << endl;
}
int main()
{
    vector<int> vec;
    for (int i = 1; i < 10; ++i)
        vec.push_back(i);
    
    list<int> lst1, lst2, lst3;
    copy(vec.begin(), vec.end(), inserter(lst1, lst1.begin()));
    copy(vec.begin(), vec.end(), back_inserter(lst2));
    copy(vec.begin(), vec.end(), front_inserter(lst3));
    print(lst1);
    print(lst2);
    print(lst3);
}