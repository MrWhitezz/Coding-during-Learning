#include<bits/stdc++.h>
using namespace std;
int rc(int k, int pos);
string bin(int n, int k);
void print_rc(int k);
int main()
{
    int k;
    //cout << "Please Enter the number of bits: ";
    cin >> k;
    print_rc(k);
    //system("pause");
    return 0;
}
int rc(int k, int pos){
    if (k == 1){
        if(pos) return 1;
        else return 0;
    }
    else{
        if (pos < 1 << (k - 1)){
            return rc(k - 1, pos);
        }
        else return rc(k - 1, (1 << k) - 1 - pos) + (1 << k - 1);
    }
}
void print_rc(int k){
    for (int i = 0; i < (1 << k); ++i){
        int val = rc(k, i);
        // cout << "The relected code of " << i << " is\t" << val
        //      << "\twhich binary is " << bin(val, k) << endl;
        cout << bin(val, k) << endl;
    }
}
string bin(int n, int k){
    string res;
    for (int i = 0; i < k; ++i){
        res += (n % 2) ? "1" : "0";
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}