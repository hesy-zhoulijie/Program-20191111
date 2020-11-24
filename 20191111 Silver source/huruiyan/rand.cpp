#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,q;
long long t[100010];
int tot=1;
int edge[200010];
int nxt[200010];
int hd[100010];
inline void add_edge(int u,int v)
{
	edge[tot]=v;
	nxt[tot]=hd[u];
	hd[u]=tot++;
}
int rk[100010];
int id[100010];
bool book[100010];
int sz[100010];
int cnt;
void dfs(int p)
{
	book[p]=true;
	id[p]=++cnt,rk[cnt]=p;
	sz[p]=1;
	for(int i=hd[p];i;i=nxt[i])
	if(!book[edge[i]]) dfs(edge[i]),sz[p]+=sz[edge[i]];
}
struct node{
	int l,r;
	int a[7];//6 divisors of a point
	long long val;
}f[100010*4];
inline void dec(node &x,long long y)
{
	while(y%2==0) x.a[1]++,y/=2;
	while(y%3==0) x.a[2]++,y/=3;
	while(y%5==0) x.a[3]++,y/=5;
	while(y%7==0) x.a[4]++,y/=7;
	while(y%11==0) x.a[5]++,y/=11;
	while(y%13==0) x.a[6]++,y/=13;
}
inline void pushup(int p)
{
	for(int i=1;i<=6;i++) f[p].a[i]=f[p*2].a[i]+f[p*2+1].a[i];
	f[p].val=f[p*2].val*f[p*2+1].val;f[p].val%=mod;
}
void build(int p,int l,int r)
{
	f[p].l=l,f[p].r=r;
	if(l==r)
	{
		dec(f[p],t[rk[l]]);
		f[p].val=t[rk[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}
void modify(int p,int x,long long y)
{
	if(f[p].l==f[p].r)
	{
		dec(f[p],y);
		f[p].val*=y;f[p].val%=mod;
		return;
	}
	int mid=(f[p].l+f[p].r)>>1;
	if(x<=mid) modify(p*2,x,y);
	else modify(p*2+1,x,y);
	pushup(p);
}
struct node3{
	long long val;
	int a[7];
};
node3 query(int p,int l,int r)
{
	node3 ans;
	if(f[p].l>=l&&f[p].r<=r)
	{
		for(int i=1;i<=6;i++) ans.a[i]=f[p].a[i];
		ans.val=f[p].val;
		return ans;
	}
	ans.val=1;
	for(int i=1;i<=6;i++) ans.a[i]=0;
	int mid=(f[p].l+f[p].r)>>1;
	if(l<=mid)
	{
		node3 tmp=query(p*2,l,r);
		ans.val*=tmp.val;ans.val%=mod;
		for(int i=1;i<=6;i++) ans.a[i]+=tmp.a[i];
	}
	if(r>mid)
	{
		node3 tmp=query(p*2+1,l,r);
		ans.val*=tmp.val;ans.val%=mod;
		for(int i=1;i<=6;i++) ans.a[i]+=tmp.a[i];
	}
	return ans;
}
int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u++,v++;
		add_edge(u,v),add_edge(v,u);
	}
	for(int i=1;i<=n;i++) scanf("%lld",&t[i]);
	dfs(1);
	build(1,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		string s;
		cin>>s;
		if(s=="SEED")
		{
			int a;
			long long b;
			scanf("%d%lld",&a,&b);
			modify(1,id[a+1],b);
		}
		else
		{
			int x;
			scanf("%d",&x);
			node3 ans=query(1,id[x+1],id[x+1]+sz[x+1]-1);
			printf("%lld ",ans.val);
			long long tmp=1;
			for(int i=1;i<=6;i++) tmp*=(ans.a[i]+1),tmp%=mod;
			printf("%lld\n",tmp);
		}
	}
	return 0;
}
