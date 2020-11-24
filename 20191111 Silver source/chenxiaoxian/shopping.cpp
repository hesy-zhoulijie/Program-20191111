#include <bits/stdc++.h>

using namespace std;

const int INF=0x7fffffff;

int n,m;
int price[305][305],money[305][305];
bool visit[305][305];

struct node{
	int to,w;
};

vector<node> g[305];

int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin>>n>>m;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			scanf("%d",&price[i][j]);
		sort(price[i]+1,price[i]+m+1);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			money[i][j]=price[i][j]+j*j-(j-1)*(j-1);
	long long ans=0;
	int min_,l,r;
	for(i=1;i<=n;++i)
	{
		min_=INF;
		for(j=1;j<=i;++j)
			for(k=1;k<=m;++k)
				if(!visit[j][k] && min_>money[j][k])
				{
					l=j;
					r=k;
					min_=money[j][k];
				}
		ans+=min_;
		visit[l][r]=true;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
