#include<bits/stdc++.h>
using namespace std;
int n,m,c[310][310],dp[310][310];

int main()
{	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			cin>>c[i][j];
		sort(c[i]+1,c[i]+m+1);
		for(int j=1;j<=m;++j)
			c[i][j]+=2*j-1;
	}
	dp[1][0]=0;
	for(int i=1;i<=m;++i)
		dp[1][i]=dp[1][i-1]+c[1][i];
	for(int i=2,ans=m;i<=n;++i)
	{
		ans+=m;
		for(int j=1,cnt=1;j<=min(n,ans);++j)
			if(cnt<=m)
			{
				if(dp[i-1][j]==-1 || dp[i-1][j]>dp[i][j-1]+c[i][cnt])
				{
					dp[i][j]=dp[i][j-1]+c[i][cnt];
					cout<<i<<' '<<j<<endl;
					++cnt;
				}
				else
					dp[i][j]=dp[i-1][j];
			}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}
