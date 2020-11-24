#include<bits/stdc++.h>
using namespace std;
int n,q,u,v,p=1e9+7,cnt,du=0,t[6];string str;
int fa[100010],s[100010],tp[100010],ys[6][100010];
int yueshu(int x)
{
	int ans=1;
	for(int i=0;i<6;i++)
	{ans*=(ys[i][x]+1);ans%=p;}
	return ans;
}
void fenjie(int x)
{
	int y=s[x],k;
	k=2;while(y%k==0){y/=k;ys[0][x]++;}
	k=3;while(y%k==0){y/=k;ys[1][x]++;}
	k=5;while(y%k==0){y/=k;ys[2][x]++;}
	k=7;while(y%k==0){y/=k;ys[3][x]++;}
	k=11;while(y%k==0){y/=k;ys[4][x]++;}
	k=13;while(y%k==0){y/=k;ys[5][x]++;}
}
void fenjie_t(int x)
{
	int y=x,k;
	k=2;while(y%k==0){y/=k;t[0]++;}
	k=3;while(y%k==0){y/=k;t[1]++;}
	k=5;while(y%k==0){y/=k;t[2]++;}
	k=7;while(y%k==0){y/=k;t[3]++;}
	k=11;while(y%k==0){y/=k;t[4]++;}
	k=13;while(y%k==0){y/=k;t[5]++;}
}
bool check(int x)
{
	for(int i=1;i<n;i++)
	{
		if(fa[i]==x&&tp[i]==0)
		{return false;}
	}
	return true;
}
int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	scanf("%d",&n);cnt=n-1;
	for(int i=1;i<n;i++)
	{scanf("%d %d",&u,&v);fa[v]=u;}
	fa[0]=0;
	for(int i=0;i<n;i++)
	{
		tp[i]=0;
		for(int j=0;j<6;j++)
		{ys[j][i]=0;}
	}
	while(cnt)
	{
		for(int i=1;i<n;i++)
		{
			if(tp[i]) continue;
			if(check(i))
			{
				du++;cnt--;
				tp[i]=du;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		fenjie(i);s[i]%=p;
	}
	for(int i=1;i<du;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(tp[j]==i)
			{
				s[fa[j]]*=s[j];
				for(int k=0;k<6;k++)
				{ys[k][fa[j]]+=ys[k][j];}
				s[fa[j]]%=p;
			}
		}
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		cin>>str;
		if(str[0]=='R')
		{
			scanf("%d",&u);
			printf("%d ",s[u]);
			printf("%d\n",yueshu(u));
		}
		if(str[0]=='S')
		{
			scanf("%d %d",&u,&v);
			fenjie_t(v);
			s[u]*=v;s[u]%=p;
			for(int i=0;i<6;i++)
			{ys[i][u]+=t[i];}
			while(fa[u]!=u)
			{
				u=fa[u];
				s[u]*=v;
				s[u]%=p;
				for(int i=0;i<6;i++)
				{ys[i][u]+=t[i];}
			}
		}
	}
	return 0;
}
