#include<bits/stdc++.h>
using namespace std;
#define maxn 250000
int n,m,x,y;
vector<pair<int,int> > circ;
int main()
{
	cin>>n>>m>>x>>y;
	int i,j;
	bool flag=true;
	//cout<<'!'<<endl;
	if(n%2==0){
		//cout<<'!'<<endl;
		for(i=0,j=0;j<m;j++)
		{
			circ.push_back(pair<int,int>(i,j));
		}
		j--;
		//cout<<i<<endl;
		while(flag){
		if((i%2==0)&&(i<n-1))
		{
			i++;
			for(;j>0;j--)
			{
				circ.push_back(pair<int,int>(i,j));
			}
			j++;
		}
		else if((i%2==1)&&(i<n-1))
		{
			//cout<<'?'<<endl;
			i++;
			for(;j<m;j++)
			{
				circ.push_back(pair<int,int>(i,j));
			}
			j--;
		}
		else if(i==n-1)
		{
			//cout<<'!'<<endl;
			for(j=0;i>0;i--)
			{
				circ.push_back(pair<int,int>(i,j));
			}
			flag=false;
		}
	   }
    }
    else if(m%2==0){
		for(i=0,j=0;i<n;i++)
		{
			circ.push_back(pair<int,int>(i,j));
		}
		i--;
		bool flag1=true;
		while(flag1){
		if((j%2==0)&&(j<m-1))
		{
			j++;
			for(i=n-1;i>0;i--)
			{
				circ.push_back(pair<int,int>(i,j));
			}
			i++;
		}
		else if((j%2==1)&&(j<m-1))
		{
			j++;
			for(i=1;i<n;i++)
			{
				circ.push_back(pair<int,int>(i,j));
			}
			i--;
		}
		else if(j==m-1)
		{
			for(i=0;j>0;j--)
			{
				circ.push_back(pair<int,int>(i,j));
			}
			flag1=false;
		}
	}
    }
    int it;
    for(it=0;it<m*n;it++)
    {
    	if(circ[it].first==x&&circ[it].second==y) break;
	}
	for(int p=it; p<m*n;p++)
	{
		cout<<circ[p].first<<' '<<circ[p].second<<endl;
	}
	for(int p=0;p<it;p++)
	{
		cout<<circ[p].first<<' '<<circ[p].second<<endl;
	}
}