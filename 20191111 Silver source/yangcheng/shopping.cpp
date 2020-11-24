#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e9;
int f[305][310]={0};
int s[310][310]={0},a[310][310];
int n,m;
int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	for(int i=0;i<=300;i++)	for(int j=0;j<=300;j++)	f[i][j]=MAXN;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int b[310];
		for(int j=1;j<=m;j++)	scanf("%d",&b[j]);
		sort(b+1,b+1+m);
		for(int j=1;j<=m;j++)
		{
			a[i][j]=b[j];
			s[i][j]=s[i][j-1]+a[i][j];
			//cout<<s[i][j]<<" ";
		}	
		//cout<<endl;
	}
	f[0][0]=0;
	for(int day=1;day<=n;day++)
	{
		for(int j=day;j<=n;j++)
		{
			for(int pre=day-1;pre<=j;pre++)
			{
				int k=j-pre;
				if(k>m)	continue;
				f[day][j]=min(f[day][j],f[day-1][pre]+s[day][k]+k*k);
			}
		}
	}
	cout<<f[n][n];
	
	
	return 0;
}
