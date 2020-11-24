#include<bits/stdc++.h>

using namespace std;
const long long M=100005;
const long long p=1e9+7;
long long n,q;
struct Node{
	long long val;
	long long index;
	long long d[10];
	Node(){
		memset(d,0,sizeof(d));
	}
}f[100005];
long long yueshu[10]={0,2,3,5,7,11,13};
bool vis[M];
long long head[M];
vector<long long>ver[M];
void add(long long x,long long y)
{
	ver[x].push_back(y);
}
queue< long long >qu;
void bfs()
{
	memset(vis,0,sizeof(vis));
	head[0]=0;
	qu.push(0);
	vis[0]=1;
	long long x;
	while(qu.size())
	{
		x=qu.front();
		qu.pop();
		for(long long i=0;i<ver[x].size();i++)
		{
			if(vis[ver[x][i]])continue;
			head[ver[x][i]]=x;
			qu.push(ver[x][i]);
			vis[ver[x][i]]=1;
		}
	}
}
Node dfs(Node x)
{
	vis[x.index]=1;
	if(x.index!=0&&ver[x.index].size()==1)return x;
	Node tmp;
	for(long long i=0;i<ver[x.index].size();i++)
	{
		if(vis[ver[x.index][i]])continue;
		f[ver[x.index][i]]=dfs(f[ver[x.index][i]]);
		tmp=f[ver[x.index][i]];
		x.val*=tmp.val;
		x.val%=p;
		for(long long j=1;j<=6;j++)
		{
			x.d[j]+=tmp.d[j];
		}
	}
	return x;
}
long long prt(Node x)
{
	long long cnt=1;
	for(long long i=1;i<=6;i++)
	{
		cnt*=(x.d[i]+1);
		cnt%=p;
	}
	return cnt;
}
void pushup(Node x,long long z)
{
	f[z].val*=x.val;
	f[z].val%=p;
	for(long long i=1;i<=6;i++)
	{
		f[z].d[i]+=x.d[i];
	}
	if(z==0)return;
	pushup(x,head[z]);
}
void change(long long x,long long y)
{
	f[x].val*=y;
	f[x].val%=p;
	long long tmp1=y,tmp2;
	Node temp;
	temp.val=y;
	for(long long i=1;i<=6;i++)
	{
		tmp2=0;
		if(tmp1==0)break;
		while(tmp1%yueshu[i]==0)
		{
			tmp2++;
			tmp1/=yueshu[i];
		}
		f[x].d[i]+=tmp2;
		temp.d[i]=tmp2;
	}
	if(x==0)return;
	pushup(temp,head[x]);
}
int main()
{
	freopen("rand,in","r",stdin);
	freopen("rand.out","w",stdout);
	cin.sync_with_stdio(false);
	cin>>n;
	long long tmp1,tmp2;
	for(long long i=1;i<=n-1;i++)
	{
		cin>>tmp1>>tmp2;
		add(tmp1,tmp2);
		add(tmp2,tmp1);
	}
	for(long long i=0;i<n;i++)
	{
		cin>>tmp1;
		f[i].index=i;
		f[i].val=tmp1;
		for(long long j=1;j<=6;j++)
		{
			tmp2=0;
			if(tmp1==0)break;
			while(tmp1%yueshu[j]==0)
			{
				tmp2++;
				tmp1/=yueshu[j];
			}
			f[i].d[j]=tmp2;
		}
	}
	memset(vis,0,sizeof(vis));
	f[0]=dfs(f[0]);
	bfs();
	cin>>q;
	string s;
	while(q--)
	{
		cin>>s;
		if(s=="RAND")
		{
			cin>>tmp1;
			cout<<f[tmp1].val<<" "<<prt(f[tmp1])<<endl;
		}
		else
		{
			cin>>tmp1>>tmp2;
			change(tmp1,tmp2);
		}
	}
	return 0;
}
