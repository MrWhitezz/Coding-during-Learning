#include<bits/stdc++.h>
#define ll long long
#define pb push_back
const int maxn=3010;
using namespace std;
int zs[100005],num=0;
bool v[200005];
int n,a[maxn],S,T,t=-1;
vector<int> g[maxn];
struct lines{
	int to,flow,cap;
}l[maxn*maxn];
int d[maxn],cur[maxn];
bool vis[maxn];
 
inline void add(int from,int to,int cap){
	l[++t]=(lines){to,0,cap},g[from].pb(t);
	l[++t]=(lines){from,0,0},g[to].pb(t);
}
 
inline bool BFS(){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(S),d[S]=0,vis[S]=1;
 
	int x; lines e;
	while(!q.empty()){
		x=q.front(),q.pop();
		for(int i=g[x].size()-1;i>=0;i--){
			e=l[g[x][i]];
			if(e.flow<e.cap&&!vis[e.to]){
				vis[e.to]=1,d[e.to]=d[x]+1;
				q.push(e.to);
			}
		}
	}
 
	return vis[T];
}
 
int dfs(int x,int A){
	if(x==T||!A) return A;
	int flow=0,f,sz=g[x].size();
	for(int &i=cur[x];i<sz;i++){
		lines &e=l[g[x][i]];
		if(d[e.to]==d[x]+1&&(f=dfs(e.to,min(e.cap-e.flow,A)))){
			A-=f,e.flow+=f;
			flow+=f,l[g[x][i]^1].flow-=f;
			if(!A) break;
		}
	}
	return flow;
}
 
inline int max_flow(){
	int an=0;
	while(BFS()){
		memset(cur,0,sizeof(cur));
		an+=dfs(S,1<<30);
	}
	return an;
}
 
inline void init(){
	for(int i=2;i<=200000;i++){
		if(!(v[i])) zs[++num]=i;
		for(int j=1,u;j<=num&&(u=zs[j]*i)<=200000;j++){
			v[u]=1;
			if(!(i%zs[j])) break;
		}
	}
}
 
inline void solve(){
	for(int i=1;i<=n;i++)
	    if(a[i]&1) add(S,i,1);
	    else add(i,T,1);
	for(int i=1;i<=n;i++) if(a[i]&1)
	    for(int j=1;j<=n;j++) if(!(a[j]&1)&&!v[a[i]+a[j]]) add(i,j,1);
	printf("%d\n",n-max_flow());
}
 
int main(){
	init();
	scanf("%d",&n),S=0,T=n+1;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]==1){
			if(v[1]) i--,n--;
			else v[1]=1;
		}
	}
 
	solve();
 
	return 0;
}