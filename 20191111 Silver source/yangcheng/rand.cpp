#include<bits/stdc++.h>
using namespace std;
const int prime[7]={0,2,3,5,7,11,13};
const int mod=1e9+7;
vector<int> q[100010];
bool v[100010]={0};
int n,ch[7]={0};

struct fxxx
{
	int fa,tot[7];
	vector<int> son;
}g[100010];

void seed(int x)
{
	memset(ch,0,sizeof(ch));
	for(int i=1;i<=6;i++)
	{
		if(x==1)	break;
		while(x%prime[i]==0)
		{
			ch[i]++;
			x/=prime[i];
		}
	}
	//for(int i=1;i<=6;i++)	printf("%d ",ch[i]);
}
int power_mod(int x,int mi)
{
	if(mi==1)	return x;
	if(mi==0)	return 1;
	if(mi%2==0)
	{
		long long u=power_mod(x,mi/2);
		u=u*u%mod;
		return u;
	}
	else
	{
		long long u=power_mod(x,mi/2);
		u=u*u*x%mod;
		return u;
	}
}
void dfst(int x)
{
	v[x]=1;
	for(int i=0;i<q[x].size();i++)
	{
		int s=q[x][i];
		if(v[s]==1)	continue;
		g[s].fa=x;
		g[x].son.push_back(s);
		dfst(s);
		for(int j=1;j<=6;j++)	g[x].tot[j]+=g[s].tot[j];
	}
}
void find(int x)
{
	long long sum=1,ans=1;
	for(int i=1;i<=6;i++)
	{
		sum=sum*power_mod(prime[i],g[x].tot[i])%mod;
		ans*=g[x].tot[i]+1;
		ans%=mod;
	}	
	cout<<sum<<" "<<ans<<endl;
}
void dl(int u,int x)
{
	seed(x);
	while(u!=-1)
	{
		for(int i=1;i<=6;i++)	g[u].tot[i]+=ch[i];
		u=g[u].fa;
	}
}
int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		q[u].push_back(v);q[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{
		int opo;	scanf("%d",&opo);
		seed(opo);
		for(int j=1;j<=6;j++)	g[i].tot[j]=ch[j];
	}
/*	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=6;j++)	cout<<g[i].tot[j]<<" ";
		cout<<endl;
	}*/
	dfst(0);
	g[0].fa=-1;
	/*int jh;	cin>>jh;
	find(jh);*/
	int D;cin>>D;
	while(D--)
	{
		string s;	cin>>s;
		int u,x;
		if(s=="SEED")
		{
			cin>>u>>x;
			dl(u,x);
		}
		if(s=="RAND")
		{
			cin>>u;
			find(u);
		}
	}
	return 0;
}
