#include<bits/stdc++.h>
using namespace std;
//#define debug 1

const long MAXN=310,MAXM=310;
long n,m,c[MAXN][MAXM];

long prefix[MAXN][MAXM];
long ans=2147483647;
long dp[MAXN][MAXN];

bool cmp(long a,long b) {return a<b;}

int main() {
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	register long i,j,k;
	for(i=0;i<MAXN;++i)
		for(j=0;j<MAXM;++j)
			c[i][j]=1000010;
	for(i=1;i<=n;++i) {
		prefix[i][0]=0;
		for(j=1;j<=m;++j) {
			scanf("%ld",&c[i][j]);
		}
		sort(c[i]+1,c[i]+m+1,cmp);
		for(j=1;j<=m;++j)
		    prefix[i][j]=prefix[i][j-1]+c[i][j]+j*j-(j-1)*(j-1);

	}
#ifdef debug
	printf("PREFIX:\n");
	for(i=1;i<=n;++i) {
		for(j=1;j<=m;++j)
			printf("%ld%c",prefix[i][j],(char)9);
		printf("\n");
	}
#endif
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(j=0;j<=m;++j)
	dp[1][j]=prefix[1][j];
	for(i=2;i<=n;++i)
		for(j=i;j<=n;++j) {
			for(k=0;k<=i;++k)
				dp[i][j]=min(dp[i][j],
				dp[i-1][j-k]+prefix[i][k]);
#ifdef debug
			printf("dp[%ld][%ld]=%ld\n",i,j,dp[i][j]);
#endif
		}
	
	cout<<dp[n][n]<<endl;
	return 0;
}
