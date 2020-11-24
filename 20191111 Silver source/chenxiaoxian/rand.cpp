#include <bits/stdc++.h>

using namespace std;

const int maxn=100010,mod=1e9+7;
int n,p[6][maxn];

void add(int x,int y,int z)
{
    while(y<=n)
	{
        p[x][y]+=z;
        y+=y&(-y);
    }
}

int query(int x,int y)
{
    int ret = 0;
    while(y)
	{
        ret+=p[x][y];
        y-=y&(-y);
    }
    return ret;
}

int getsum(int x,int l,int r)
{
    return query(x,r)-query(x, l-1);
}

int a[maxn],L[maxn],R[maxn],dfsclk;
vector <int> graph[maxn];
int prime[]={2,3,5,7,11,13};

void dfs(int u,int pre)
{
    L[u]=++dfsclk;
    for(int i=0;i<6;i++)
	{
        int num = 0;
        while(a[u]%prime[i]==0)
		{
            num++;
            a[u]/=prime[i];
        }
        add(i,L[u],num);
    }
    for(int i=0;i<graph[u].size();i++)
	{
        if(graph[u][i]==pre)
			continue;
        dfs(graph[u][i],u);
    }
    R[u]=dfsclk;
}

long long qp(long long a,long long n)
{
    long long ret=1;
    while(n)
	{
        if(n&1)
			ret=(ret*a%mod)%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret;
}
 
int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
	{
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<n;i++)
		cin>>a[i];
    int q,x,y;
    string op;
    dfs(0,-1);
    cin>>q;
    while(q--)
	{
        cin>>op>>x;
        if(op=="SEED")
		{
            cin>>y;
            for(int i=0;i<6;i++)
			{
                int num = 0;
                while(y%prime[i]==0)
				{
                    y/=prime[i];
                    num++;
                }
                add(i,L[x],num);
            }
        }
		else
		{
            long long a1=1,a2=1;
            for(int i=0;i<6;i++)
			{
                int sum=getsum(i,L[x],R[x]);
                a1=a1*qp(prime[i],sum)%mod;
                a2=a2*(sum+1)%mod;
            }
            cout<<a1<<' '<<a2<<endl;
        }
    }
    return 0;
}
