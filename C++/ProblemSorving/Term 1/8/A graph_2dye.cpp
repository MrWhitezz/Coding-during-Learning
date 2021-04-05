#include<iostream>
#include<map>
using namespace std;
bool check (short a[], int n, multimap<int,int> &G);
bool dye (short a[], int p, multimap<int,int> &G);
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, m;
        cin >> n >> m;
        short vert[n];
        for (int j = 0; j < n; j++)
            vert[j] = -1;
        multimap<int,int> G;
        for (int j = 0; j < m; j++)
        {
            int fir, sec;
            cin >> fir >> sec;
            G.insert(pair<int,int>(fir,sec));
            G.insert(pair<int,int>(sec,fir));
        }
        if (check(vert,n,G))
        {
            cout << "yes" << endl;
            for (int k = 0; k < n; k++)
            {
                if (vert[k]) cout << "blue" << endl;
                else cout << "red" << endl;
            }
        }
        else cout << "no" << endl;
    }

    return 0;
}
bool check (short a[], int n, multimap<int,int> &G)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            a[i] = 0;
            if (!dye(a, i, G)) return false;
        }
    }
    return true;

}
bool dye (short a[], int p, multimap<int,int> &G)
{
    auto pr = G.equal_range(p + 1);
    if (pr.first != G.end())
    {
        for (auto it = pr.first; it != pr.second; it++)
        {
            if (a[it->second - 1] == -1)
            {
                a[it->second - 1] = a[p] == 0 ? 1 : 0;
                if (!dye(a,it->second - 1, G)) return false;
            }
            else if ((a[p] + a[it->second - 1]) != 1)
                return false;
        }
    }
    return true;
}
