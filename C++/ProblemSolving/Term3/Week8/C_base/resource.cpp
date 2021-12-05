#include<bits/stdc++.h>
using namespace std;

#define Com complex<double>
int Rev[1000001];
void Rader(int n)
{
    int len=1<<n;
    for(int i=0;i<len;i++)
    Rev[i]=(Rev[i>>1]>>1)|((i&1)<<(n-1));   
}
const
    double pi=acos(-1);
const
int Mod=(int)1e9+7;

int Mul(int a,int b)
{
    a=a*1ll*b%Mod;
    return a;
}
int Pow(int a,int x)
{
    int res=1;
    if(x==-1)return 0;
    for(;x;x>>=1,a=a*1ll*a%Mod)if(x&1)res=res*1ll*a%Mod;
    return res;
}

int Add(int a,int b)
{
    a+=b;
    if(a<0)a+=Mod;
    else if(a>=Mod)a-=Mod;
    return a;
}
int FF;
void FFT(Com*A,int n,int fl)
{
    int len=1<<n;
    FF+=n*(1<<n);
    Rader(n);
    for(int i=0;i<len;i++)
    if(Rev[i]>i)swap(A[Rev[i]],A[i]);
    for(int i=1;i<len;i*=2)
    {
        Com W0(cos(pi/i),fl*sin(pi/i));
        for(int j=0;j<len;j+=i*2)
        {
            Com W(1,0);
            for(int k=0;k<i;k++)
            {
                Com X=A[j+k],Y=W*A[j+k+i];
                A[j+k]=X+Y;
                A[j+k+i]=X-Y;
                W*=W0;
            }
        }
    }
    if(fl==-1)
        for(int i=0;i<len;i++)
            A[i]/=len;
}

Com Base[1000001],Cur[1000001];
int Ans[1000001];
int A[20][1000001],Len[20];

const
    double eps=1e-6;
int Data[100001];

void Solve(int l,int r,int *Res,int &Len)
{
    if(l==r)
    {
        Len=0;
        int A=Data[l];
        while(A)
            Res[Len++]=A&1,A>>=1;
        return;
    }

    int Llen,Rlen;
    int C=0,B=1;
    while(B<(r-l+1))
    B*=2,C++;
    B/=2,C--;
    int fd=4<<C+1,L[4<<C+1],R[4<<C+1];
    for(int i=0;i<fd;i++)L[i]=R[i]=0;

    Solve(l,l+B-1,L,Llen);
    Solve(l+B,r,R,Rlen);
    int t=C;
    int ll=0,rr=0;
    while((1<<ll)<Llen)ll++;
    while((1<<rr)<Llen)rr++;
    C=max(max(ll,rr),::Len[C])+1;
    for(int i=0;i<(1<<C);i++)
        Base[i]=R[i];
    for(int i=0;i<(1<<C);i++)
        Cur[i]=A[t][i];
    FFT(Base,C,1);FFT(Cur,C,1);
    for(int i=0;i<(1<<C);i++)
        Cur[i]*=Base[i];
    FFT(Cur,C,-1);
    for(int i=0;i<(1<<C);i++)
        Res[i]=L[i]+(int)(Cur[i].real()+0.5);

    Len=0;
    for(int i=0;i<(1<<C);i++)
        if(Res[i])
        Res[i+1]+=Res[i]>>1,Res[i]&=1,Len=i+1;
}

int Cnt[300001],X[300001];
char S[300001];
int main()
{
    A[0][0]=0,A[0][1]=1,A[0][2]=0,A[0][3]=1;
    Len[0]=2;
    for(int i=1;i<=15;i++)
    {
        int C=0;
        C=Len[i]=Len[i-1]+1;
        for(int j=0;j<(1<<C);j++)
            Cur[j]=A[i-1][j];
        FFT(Cur,C,1);   
        for(int j=0;j<(1<<C);j++)
            Cur[j]*=Cur[j];
        FFT(Cur,C,-1);
        for(int j=0;j<(1<<C);j++)
        A[i][j]=(int)(Cur[j].real()+0.5);
        for(int j=0;j<(1<<C);j++)
        if(A[i][j])
        A[i][j+1]+=A[i][j]>>1,A[i][j]&=1;
    }
    int n,N;
    scanf("%d",&N);
    int ans=0;
    int ML=0;
    while(N--)
    {
        scanf("%s",S);
        n=strlen(S);
        for(int i=0;i<n;i++)
            Data[i]=S[n-i-1]-'0';
        int tt;
        Solve(0,n-1,Ans,tt);
        while(tt--)
        putchar('0'+Ans[tt]);
        puts("");
    }

    return 0;   
}