#include<bits/stdc++.h>
using namespace std;
int c[305][305];
long long dp[305][305];
long long qian[305][305];
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&c[i][j]);
		}
		sort(c[i]+1,c[i]+1+m);
		for(int j=1;j<=m;j++){
			qian[i][j]=qian[i][j-1]+c[i][j];
		}
		for(int j=0;j<=n;j++){
			dp[i][j]=21474836470000;
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%lld ",qian[i][j]);
		}
		printf("\n");
	}
*/	
	
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
//		dp[1][i]=i*i+qian[1][i];
	}
	for(int i=0;i<=m;i++){
		dp[1][i]=i*i+qian[1][i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				dp[i][j]=min(dp[i][j],dp[i-1][j-k]+k*k+qian[i][k]);
				dp[i][j]=min(dp[i][j],dp[i-1][j]);
//				printf("%lld ",dp[i-1][j-k]);
			}			
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lld ",dp[i][j]);
		}
		printf("\n");
	}
*/	printf("%lld",dp[n][n]);
	return 0;
}
/*
3 2
1 1
100 100
10000 10000
*/
