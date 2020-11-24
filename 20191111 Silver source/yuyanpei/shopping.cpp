#include<bits/stdc++.h>
using namespace std;
int n,m;
priority_queue <long long,vector<long long>,greater<long long> > x[310];
priority_queue <long long,vector<long long>,greater<long long> > f[310];

int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int a;
			cin>>a;
			x[i].push(a);
		}

	for(int i=1;i<=n;i++)
	{
		int num=1;
		for(int j=1;j<=m;j++)
		{
			int a=x[i].top()+num;
			x[i].pop();
			f[i].push(a);
			num += 2;
		}
	}


	long long ans[310];
	memset(ans,0x3f,sizeof(ans));
	ans[0]=0;
	for(int i=1;i<=n;i++)
	{
		int t;
		for(int j=1;j<=i;j++)
			if(ans[i]>f[j].top() && !f[j].empty())
			{
				t=j;
				ans[i]=f[j].top()+ans[i-1];
			}
		f[t].pop();
	}
	cout<<ans[n]<<endl;
	return 0;	
}
