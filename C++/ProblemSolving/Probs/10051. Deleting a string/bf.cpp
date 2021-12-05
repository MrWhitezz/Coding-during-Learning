#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
string rido(string st, int x) {
	int i=0;
	while (x - i >= 0 && x + i < st.size() && st[x - i] == st[x + i])
		i++;
	return st.substr(0, x - i + 1) + st.substr(x + i);
}
string ride(string st, int x) {
	int i = 0;
	while (x - i >= 0 && x + i + 1 < st.size() && st[x - i] == st[x + i + 1])
		i++;
	return  st.substr(0, x - i + 1) + st.substr(x + i + 1);
}
int main(){
	int n,i,j,misi=INT_MAX,ans=0;
	string s;
	map<string, bool> ma;
	cin >> n >> s;
	ma[s] = 1;
	vector<string> bfs;
	vector<string> tem;
	bfs.push_back(s);
	while (misi) {
		tem.clear();
		for (i = 0; i != bfs.size(); i++) {
			for (j = 0; j != bfs[i].size()-1; j++) {
				if (!ma.count(rido(bfs[i], j)))
					tem.push_back(rido(bfs[i], j));
				if (!ma.count(ride(bfs[i], j)))
					tem.push_back(ride(bfs[i], j));
			}
			if (!ma.count(bfs[i].substr(0, bfs[i].size() - 1)))
				tem.push_back(bfs[i].substr(0, bfs[i].size() - 1));
		}
		bfs = tem;
		ans++;
		for (i = 0; i != bfs.size(); i++)
			if (bfs[i].size() < misi)
				misi = bfs[i].size();
	}
	cout << ans;
	return 0;
}
