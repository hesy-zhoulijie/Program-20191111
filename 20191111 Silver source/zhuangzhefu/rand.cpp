#include<bits/stdc++.h>

using namespace std;

struct node{
	int sum;
	long long g[3000];
};

long long t[3000];
node son[3000];
long long q=1000000007;

long long count(long long x)
{
	int ans=0;
	for(int i=1;i<=x;++i)
	{
		if(x%i==0)
			ans=(ans+1)%q;
	}
	return ans;
}

long long find(int x)
{
	if(son[x].sum==1) return t[x];
	int number=son[x].sum-1;
	int ans=t[x];
	for(int i=1;i<=number;++i)
	{
		ans=ans*find(son[x].g[i])%q;
	}
	return ans;
}

int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	int n=0,p=0;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		son[i].sum=1;
	}
	for(int i=1;i<n;++i)
	{
		int a=0,b=0;
		cin>>a>>b;
		son[a].g[son[a].sum]=b;
		++son[a].sum;
	}
	for(int i=0;i<n;++i)
	{
		cin>>t[i];
	}
	cin>>p;
	for(int i=1;i<=p;++i)
	{
		string a;
		int y=0,z=0;
		cin>>a;
		if(a[0]=='R')
		{
			cin>>y;
			int k=find(y);
			cout<<k<<" "<<count(k)<<endl;
		}
		if(a[0]=='S')
		{
			cin>>y>>z;
			t[y]=t[y]*z;
		}
	}
	return 0;
}
