#include<bits/stdc++.h>
using namespace std;
int row[9],col[9],grid[9];//000000000~111111111	���������� 1��ʾ������
//2^9=32*16=512		2^8+5=256+5=261
int cnt[512],num[261];//���������к���1�ĸ���(����״̬�п�ѡ������ĸ���)	lowbit��Ӧ��hash
int rec[9][9];
inline int g(int x,int y){//�����ԵĹ�ʽ
	return ((x/3)*3)+(y/3);
}
void flip(int x,int y,int z){//�Ը�λ����z��Ļ��ݺͱ��(xor)
	//δ���->���->δ���(xor�Ŀ�����)
	row[x]^=1<<z;//1<<z=pow(2,z)
	col[y]^=1<<z;
	grid[g(x,y)]^=1<<z;
}
bool dfs(int now){//��ǰ��now���������״̬
	if(!now)	return true;//������
	int temp=10,x,y;
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			if(rec[i][j])	continue;
			int val=row[i]&col[j]&grid[g(i,j)];//��λ���Ͽ���������ĸ���
			if(!val)	return false;//1��Ҳ���������
			if(temp>cnt[val]){//tempȡ��ǰλ�ÿ���������ٵ����ĸ���������¼�����λ��
				temp=cnt[val];
				x=i;y=j;
			}
		}
	}
	//(x,y)����������ĸ���
	int val=row[x]&col[y]&grid[g(x,y)];
	for(;val;val-=val&(-val)){
		int z=num[val&(-val)];
//		rec[x][y]=z;//Error
		rec[x][y]=z+1; //֮���Լ�1������Ʊ������Ķ����й�
		flip(x,y,z);
//		flip(x,y,z-1);//Error
		if(dfs(now-1))	return true;
		rec[x][y]=0;
		flip(x,y,z);
//		flip(x,y,z-1);//Error
	}
	return false;//�޽⣬������һ��
}
int main(){
	for(int i=0;i<(1<<9);++i){
		//i�Ķ��������к���1�ĸ��� ������״̬�п�ѡ������ĸ���
		//Ԥ������ʱ�临�Ӷ�
		//e.g:cnt[100010001(��������)] = 3
		for(int j=i;j;j-=j&(-j)){
			++cnt[i];
		}
	}
	for(int i=0;i<9;++i){
		//lowbit(1 << i)��hash,���ҳ�lowbit(1 << i)����Ӧ�ĵ�һ��1��λ��
		num[1<<i]=i;
	}
	for(int i=0;i<9;++i){
		//��ʼ���У��У��Ź���������
		//ÿ������������
		row[i]=col[i]=grid[i]=(1<<9)-1;
	}
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			scanf("%d",&rec[i][j]);
		}
	}
	//��ʼ��������
	int tot=0;
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			if(rec[i][j]) flip(i,j,rec[i][j]-1);//���б��	֮���� -1��flip�����Ķ����й�
			else	++tot;//���rec[i][j]��0����ʾ��λ�û�û������
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
