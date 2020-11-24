#include<bits/stdc++.h>

using namespace std;

long long f[500][500],c[500][500],pp[2500];

int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout); 
	int count=0;
	int m=0,n=0;
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		int c[500];
		for(int j=0;j<m;++j)
		{
			cin>>c[j];
		}
		sort(c,c+m);
		int check=0;
		for(int j=0;j<m;++j)
		{
			f[i][j]=c[j];
			if(f[i][j]!=f[i-1][j]&&i!=0)
				check=1;
		}
		if(check==0)
			++count;
	}
	if(count==n)
	{
		cout<<f[0][0]*n*2;
		return 0;
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(j==0)
			{
				c[i][j]=f[i][j]+1;
			}
			c[i][j]=f[i][j]+(j+1)*(j+1)-c[i][j-1]+f[i][j-1];
		}
	}
//	for(int i=0;i<n;++i)
//	{
//		for(int j=0;j<m;++j)
//		{
//			cout<<c[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int uu=-1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			uu++;
			pp[uu]=c[i][j];
		}
	}
	sort(pp,pp+uu);
	long long ans=0;
	for(int i=0;i<n;++i)
	{
		ans=ans+pp[i];
	}
	cout<<ans<<endl;
	return 0;
}
