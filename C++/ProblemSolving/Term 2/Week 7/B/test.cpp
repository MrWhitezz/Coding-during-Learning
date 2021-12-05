#include<bits/stdc++.h>
using namespace std;
void get_Post (int Pre[], int In[], int Post[], int n);
int main()
{
    int n;
    cin >> n;
    int Pre[n], In[n], Post[n];
    for (int i = 0; i < n; ++i)
        cin >> Pre[i];
    for (int i = 0; i < n; ++i)
        cin >> In[i];  
    get_Post(Pre, In, Post, n);  
    for (int i = 0; i < n; ++i)
        cout << Post[i] << " ";
    return 0;
}
void get_Post (int Pre[], int In[], int Post[], int n){
    if (n == 0) return;
    Post[n - 1] = Pre[0];
    if (n == 1) return;
    int root = Pre[0], i = 0;
    while (In[i] != root) ++i;
    get_Post(Pre + 1, In, Post, i);
    get_Post(Pre + i + 1, In + i + 1, Post + i, n - i - 1);
}