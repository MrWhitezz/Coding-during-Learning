#include<bits/stdc++.h>
using namespace std;
int n,m,ans,mi=INT_MAX;
const int N = 60;
char c[N][N];
int main()
{
	int i,j,k,g;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++) cin>>c[i][j];
	for(i=1;i<=n-2;i++)//���ڰ�ɫ���滹����ɫ�ͺ�ɫ������i���������ı߽磩ö�ٵ���n-2��
	  for(j=i+1;j<=n-1;j++)//j�������ı߽磩����Ҫ��i��1��ͬ��ö�ٵ���n-1�����������Լ���ö�ٴ���
	  {
	    ans=0;//��ʼ��
        //׳�۵�ö����������
	    for(k=1;k<=i;k++)
	      for(g=1;g<=m;g++) if(c[k][g]!='W') ans++;
	    for(k=i+1;k<=j;k++)
	      for(g=1;g<=m;g++) if(c[k][g]!='B') ans++;
	    for(k=j+1;k<=n;k++)
	      for(g=1;g<=m;g++) if(c[k][g]!='R') ans++;
        //ǿ��֢�����X�m��������Щ����ʾ�ܿ���
	    mi=min(ans,mi);//���´�
	  }
	cout<<mi<<endl;
	return 0;
}
