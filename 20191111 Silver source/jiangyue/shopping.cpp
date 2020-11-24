#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[310][310],f[310][310],sum[310][310];
int main() {
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	memset(f,0x3F,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&c[i][j]);
	for(int i=1;i<=n;i++)
		sort(c[i]+1,c[i]+m+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum[i][j]=sum[i][j-1]+c[i][j]+j*j-(j-1)*(j-1);
	for(int i=0;i<=n;i++)
		f[i][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=m && j+k<=n;k++)  {//从0开始 今日可以不购买任意东西 
//				cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<'\n';
				f[i][j+k]=min(f[i-1][j]+sum[i][k],f[i][j+k]);
//				cout<<f[i][j]<<' '<<sum[i][k]<<' '<<f[i-1][j-k]<<'\n';
			}
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=n;j++)
//			printf("%d ",f[i][j]);
//		printf("\n");
//	}
	printf("%d",f[n][n]);
	return 0;
}
/*
3 2
1 1
100 100
10000 10000
*/
