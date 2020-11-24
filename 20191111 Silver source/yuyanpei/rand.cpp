#include<bits/stdc++.h>
using namespace std;
const int inf=1000000007;
vector<long long> f[5010];
long long n,q;
long long tree[5010];
long long ans=1;

void yueshu(long long x)
{
	long long sum=0;
	for(int i=1;i<=x;i++)
		if(x%i==0)	
			sum=(sum+1)%inf; 
	cout<<sum<<endl;
	return;
}

long long dfs(long long y)
{
	if(f[y].size()==1)	return ans * tree[y];	
	for(int i=1;i<=f[y].size();i++)	dfs(f[y][i]);
}

int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		long long a,b;
		cin>>a>>b;
		f[a].push_back(b);
	}
	for(int i=0;i<n;i++)	cin>>tree[i];
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		string a;
		cin>>a;
		if(a=="RAND")
		{
			long long u;
			cin>>u;
			ans=1;
			cout<<dfs(u)<<' ';
			yueshu(ans);
		}
		else if(a=="SEED")
		{
			long long u,x;
			cin>>u>>x;
			tree[u] *= x;
		}
	}
	return 0;
}
