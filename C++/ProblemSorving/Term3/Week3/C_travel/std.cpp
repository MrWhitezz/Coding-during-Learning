#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
    return x*f;
}
const int N=1e3+7,mo=1e9+7;
int n,m,tot,ans[N];
vector <int> e,V[N][10],Q[N];//V是边,Q是BFS的队列，队列为啥是vector等等就知道了...
bool vis[N];
int main()
{
    n=read(),m=read(); int a,b;
    tot=n;
    for(int i=1;i<=m;i++)
    {
        a=read(),b=read(); int t=read(),c; e.clear();
        while(t) c=t%10,t/=10,e.push_back(c);
        reverse(e.begin(),e.end()); int pre=a,len=e.size();
        for(int j=0;j<len;j++)//拆点
        {
            int np=(j==len-1 ? b : ++tot);
            V[pre][e[j]].push_back(np),pre=np;
        }
        pre=b;
        for(int j=0;j<len;j++)//无向图两边都要拆
        {
            int np=(j==len-1 ? a : ++tot);
            V[pre][e[j]].push_back(np),pre=np;
        }
    }
    int T=0; Q[++T].push_back(1); vis[1]=1;
    for(int i=1;i<=T;i++)
        for(int j=0;j<=9;j++)//优先走数字小的
        {
            bool flag=0;
            for(auto x: Q[i])//对于同一个i,Q[i]中的点的ans都是一样的
                for(auto v: V[x][j])//走到下一层
                {
                    if(vis[v]) continue;//走过就不用再走了
                    vis[v]=flag=1; Q[T+1].push_back(v);
                    ans[v]=(10ll*ans[x]+j)%mo;//更新答案
                }
            if(flag) T++;
        }
    for(int i=2;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}