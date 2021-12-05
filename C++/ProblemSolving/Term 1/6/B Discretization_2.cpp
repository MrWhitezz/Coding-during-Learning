#include<iostream>
#include<map>
using namespace std;
void printMap (map<int, int> &f)
{
    for (map<int, int> ::iterator it = f.begin(); it != f.end(); it++)
        cout << "key = " << it -> first << " value = " << it -> second << endl;
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map <int, int> g;
    for (int i = 0; i < n; i++)
        g.insert(pair <int, int> (a[i], i + 1));
    map <int, int> f;
    for (map <int, int> :: iterator it = g.begin(); it != g.end(); it++)
        f.insert(pair <int, int> (it -> second ,0 ));
    int i = 1;
    for (map <int, int> :: iterator it = f.begin(); it != f.end(); it++, i++)
        it -> second = i;

    //int i = 1;
    //for ( map<int, int>::iterator it = f.begin(); it != f.end(); it++, i++)
        //it->second = i;
    //printMap(f);


    for (int i = 0; i < n; i++)
        cout << f[g[a[i]]] << " ";

    return 0;
}
