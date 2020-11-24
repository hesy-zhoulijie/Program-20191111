#include<bits/stdc++.h>

using namespace std;
const long long M=305;
long long n,m;
long long price[M][M]={0};
long long temp[M];
long long f[M][M];
int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin.sync_with_stdio(false);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			cin>>temp[j];
		}
		sort(temp+1,temp+m+1);
		for(long long j=1;j<=m;j++)
		{
			price[i][j]=price[i][j-1]+temp[j]+j*j-(j-1)*(j-1);
		}
	}
	memset(f,0x3f3f3f,sizeof(f));
	f[0][0]=0;
	long long x,y;
	for(long long i=1;i<=n;i++)
	{
		x=min(n,i*m);
		for(long long j=i;j<=x;j++)
		{
			y=min(n,(i-1)*m);
			for(long long p=i-1;p<=y;p++)
			{
				if(j-p>=0&&j-p<=m)f[i][j]=min(f[i][j],f[i-1][p]+price[i][j-p]);
			}
		}
	}
	cout<<f[n][n]<<endl;
	return 0;
}
