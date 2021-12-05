#include<bits/stdc++.h>
using namespace std;
int row[9],col[9],grid[9];//000000000~111111111	可行性数组 1表示可以填
//2^9=32*16=512		2^8+5=256+5=261
int cnt[512],num[261];//二进制数中含有1的个数(各个状态中可选择的数的个数)	lowbit对应的hash
int rec[9][9];
inline int g(int x,int y){//很灵性的公式
	return ((x/3)*3)+(y/3);
}
void flip(int x,int y,int z){//对该位置填z后的回溯和标记(xor)
	//未标记->标记->未标记(xor的可逆性)
	row[x]^=1<<z;//1<<z=pow(2,z)
	col[y]^=1<<z;
	grid[g(x,y)]^=1<<z;
}
bool dfs(int now){//当前有now个数可填的状态
	if(!now)	return true;//填完了
	int temp=10,x,y;
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			if(rec[i][j])	continue;
			int val=row[i]&col[j]&grid[g(i,j)];//该位置上可以填的数的个数
			if(!val)	return false;//1个也不能填，回溯
			if(temp>cnt[val]){//temp取当前位置可以填的最少的数的个数，并记录下这个位置
				temp=cnt[val];
				x=i;y=j;
			}
		}
	}
	//(x,y)可以填的数的个数
	int val=row[x]&col[y]&grid[g(x,y)];
	for(;val;val-=val&(-val)){
		int z=num[val&(-val)];
//		rec[x][y]=z;//Error
		rec[x][y]=z+1; //之所以加1与二进制标记数组的定义有关
		flip(x,y,z);
//		flip(x,y,z-1);//Error
		if(dfs(now-1))	return true;
		rec[x][y]=0;
		flip(x,y,z);
//		flip(x,y,z-1);//Error
	}
	return false;//无解，返回上一层
}
int main(){
	for(int i=0;i<(1<<9);++i){
		//i的二进制数中含有1的个数 即各个状态中可选择的数的个数
		//预处理降低时间复杂度
		//e.g:cnt[100010001(二进制数)] = 3
		for(int j=i;j;j-=j&(-j)){
			++cnt[i];
		}
	}
	for(int i=0;i<9;++i){
		//lowbit(1 << i)的hash,能找出lowbit(1 << i)所对应的第一个1的位置
		num[1<<i]=i;
	}
	for(int i=0;i<9;++i){
		//初始化行，列，九宫格标记数组
		//每个数都可以填
		row[i]=col[i]=grid[i]=(1<<9)-1;
	}
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			scanf("%d",&rec[i][j]);
		}
	}
	//初始化计数器
	int tot=0;
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			if(rec[i][j]) flip(i,j,rec[i][j]-1);//进行标记	之所以 -1与flip函数的定义有关
			else	++tot;//如果rec[i][j]是0，表示该位置还没有填数
		}
	}
	cout << row[0] << endl;
	dfs(tot);
//	printf("\n");
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			printf("%d ",rec[i][j]);
		}
		printf("\n");
	}
	return 0;
}
