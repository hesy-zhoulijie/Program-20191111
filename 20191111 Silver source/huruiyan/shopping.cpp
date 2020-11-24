#include<bits/stdc++.h>
#define inf 999999999
using namespace std;
int n,m;
int a[310][310];
int f[310][310];
int s[310][310];
int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+m+1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	s[i][j]=s[i][j-1]+a[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) s[i][j]+=j*j;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++) f[i][j]=inf;
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	for(int k=0;k<=j;k++)
	{
		if(j-k>m) continue;
		f[i][j]=min(f[i][j],f[i-1][k]+s[i][j-k]);
	}
	printf("%d\n",f[n][n]);
	return 0;
}

