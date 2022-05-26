#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
typedef long long ll;
const ll MOD=1e6;
const ll BOUND=1e6+5;
const ll mod=1e9+7;
ll n,T,p,q,x,y,z,ans0=0,ans1=0;
struct node
{
    ll Val,Left,Right,Max,Or;//Property of itself
	ll PreMax,PreOr,PostMax,PostOr;//Property of elements that can "consume" other elements in the stack;
}A[BOUND];
void Preprocess()
{
	ll temp;
	stack<ll>S;
	while(!S.empty())S.pop();
	for(ll i=1;i<=n+1;i++)
	if(S.empty()||A[S.top()].Val<=A[i].Val)S.push(i);
	else
	{
		while(!S.empty()&&A[S.top()].Val>A[i].Val)
		{
			temp=S.top();
			S.pop();
			A[temp].Right=i-1;
			A[temp].Max=max(A[temp].Max,max(A[temp].Val,A[i].PreMax));
			A[temp].Or=A[temp].Or|A[i].PreOr;
			A[i].PreMax=max(A[temp].PreMax,max(A[i].PreMax,A[temp].Val));
			A[i].PreOr=A[temp].PreOr|(A[i].PreOr|A[temp].Val);
		}
		S.push(i);
	}
	
	while(!S.empty())S.pop();
	for(ll i=n;i>=0;i--)
	if(S.empty()||A[S.top()].Val<=A[i].Val)S.push(i);
	else
	{
		while(!S.empty()&&A[S.top()].Val>A[i].Val)
		{
			temp=S.top();
			S.pop();
			A[temp].Left=i+1;
			A[temp].Max=max(A[temp].Max,max(A[temp].Val,A[i].PostMax));
			A[temp].Or=A[temp].Or|A[i].PostOr;
			A[i].PostMax=max(A[temp].PostMax,max(A[i].PostMax,A[temp].Val));
			A[i].PostOr=A[temp].PostOr|(A[i].PostOr|A[temp].Val);
		}
		S.push(i);
	}
}
int main()
{
	scanf("%lld",&T);
	while(T)
	{
		T--;
		scanf("%lld",&n);
		scanf("%lld%lld%lld%lld%lld",&p,&q,&x,&y,&z);
		A[1].Val=p,A[2].Val=q;
		for(ll i=3;i<=n;i++)
		A[i].Val=(x*A[i-2].Val+y*A[i-1].Val+z)%MOD+1;
		for(ll i=1;i<=n;i++)
		{
			A[i].Left=i,A[i].Right=i;
			A[i].Max=A[i].Val,A[i].Or=A[i].Val;
			A[i].PreMax=0,A[i].PreOr=0;
			A[i].PostMax=0,A[i].PostOr=0;
		}
		A[n+1].Val=-1;
		A[n+1].Left=n+1,A[n+1].Right=n+1;
		A[n+1].Max=A[n+1].Val,A[n+1].Or=A[n+1].Val;
		A[n+1].PreMax=0,A[n+1].PreOr=0;
		A[n+1].PostMax=0,A[n+1].PostOr=0;
		
		A[0].Val=-1;
		A[0].Left=0,A[0].Right=0;
		A[0].Max=A[0].Val,A[0].Or=A[0].Val;
		A[0].PreMax=0,A[0].PreOr=0;
		A[0].PostMax=0,A[0].PostOr=0;
		Preprocess();
		
		ans0=0,ans1=0;
		ll temp0,temp1;
		for(ll i=1;i<=n;i++)
		{ 
		    temp0=0,temp1=0;
		    temp0=A[i].Val*(A[i].Max-A[i].Val)*(A[i].Right-A[i].Left+1);
		    temp1=temp0/mod;
		    temp0%=mod;
		    temp1*=A[i].Or;
		    temp0*=A[i].Or;
		    temp1+=temp0/mod;
		    temp0%=mod;
		    if(temp1>ans1||(temp1==ans1&&temp0>ans0))ans1=temp1,ans0=temp0;
		} 
		cout<<ans0<<endl;
	}
	return 0;
}