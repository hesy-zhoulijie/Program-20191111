#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int su1[6]={2,3,5,7,11,13};
long long anss[6],an=1;
struct node{
	vector <int > son;
	int val;
	long long ans[6];
} tree[100010];
int n,q;

void ask(int x)
{
	an*=tree[x].val;
	an%=P;
	for(int i=0;i<6;++i)
		anss[i]+=tree[x].ans[i];
	int m=tree[x].son.size();
	for(int i=0;i<m;++i)
		ask(tree[x].son[i]);
}

void build()
{
	for(int i=0;i<n;++i)
	{
		int t=tree[i].val;
		for(int j=0;j<6;++j)
		{
			tree[i].ans[j]=0;
			while(t%su1[j]==0)
			{
				t/=su1[j];
				tree[i].ans[j]++;
			}
		}
	}
}

void add(int x,int y)
{
	tree[x].val=(tree[x].val*y)%P;
	for(int i=0;i<6;++i)
		while(y%su1[i]==0)
		{
			y/=su1[i];
			tree[x].ans[i]++;
		}
}

int main()
{	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	cin>>n;
	for(int i=1,x,y;i<n;++i)
	{
		cin>>x>>y;
		tree[x].son.push_back(y);
	}
	for(int i=0;i<n;++i)
		cin>>tree[i].val;
	build();
	cin>>q;
	while(q--)
	{
		int x,y;
		string a;
		cin>>a;
		if(a=="SEED")
		{
			cin>>x>>y;
			add(x,y);
		}
		else
		{
			cin>>x;
			anss[0]=1;anss[1]=1;anss[2]=1;
			anss[3]=1;anss[4]=1;anss[5]=1;
			an=1;
			ask(x);
			long long num=1;
			for(int i=0;i<6;++i)
				num=(num*anss[i])%P;
			cout<<an<<' '<<num<<endl;
		}
	}
	return 0;
}
