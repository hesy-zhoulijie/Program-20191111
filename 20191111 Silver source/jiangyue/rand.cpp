#include<bits/stdc++.h>
#define N 1000010
#define MOD 1000000007
#define ll long long
using namespace std;
int n,q,c[N];
struct tree {
	int fa,no;
	vector<int> son;
	int s[6];
	/*s[0] 代表 2
	  s[1] 代表 3
	  s[2] 代表 5
	  s[3] 代表 7
	  s[4] 代表 11 
	  s[5] 代表 13*/
}t[N];
ll quick_pow(ll a,ll b,ll c) {
	if(b==0) return 1;
	long long ans=1;
	ans=quick_pow(a,b>>1,c);
	ans=ans*ans%c;
	if(b&1) ans=ans*a%c;
	return ans;
}
pair<int,int> query(int x) {
	long long ans1=1,ans2=1;
	for(int i=0;i<6;i++)
		ans1=ans1*(t[x].s[i]+1)%MOD;
	ans2=ans2*quick_pow(2,t[x].s[0],MOD)%MOD;
	ans2=ans2*quick_pow(3,t[x].s[1],MOD)%MOD;
	ans2=ans2*quick_pow(5,t[x].s[2],MOD)%MOD;
	ans2=ans2*quick_pow(7,t[x].s[3],MOD)%MOD;
	ans2=ans2*quick_pow(11,t[x].s[4],MOD)%MOD;
	ans2=ans2*quick_pow(13,t[x].s[5],MOD)%MOD;
	return make_pair(ans1,ans2);
}
void add(int u,int x) {
	int tx=x;
	while(x%2==0) x/=2,t[u].s[0]++;
	while(x%3==0) x/=3,t[u].s[1]++;
	while(x%5==0) x/=5,t[u].s[2]++;
	while(x%7==0) x/=7,t[u].s[3]++;
	while(x%11==0) x/=11,t[u].s[4]++;
	while(x%13==0) x/=13,t[u].s[5]++;
	if(t[u].fa!=n+1) add(t[u].fa,tx);
}
inline int findfa() {
	for(int i=0;i<n;i++)
		if(t[i].fa==n+1)
			return i;
}
void build(int x) {
	t[x].s[0]=0;t[x].s[1]=0;t[x].s[2]=0;t[x].s[3]=0;t[x].s[4]=0;t[x].s[5]=0;
	while(c[x]%2==0) c[x]/=2,t[x].s[0]++;
	while(c[x]%3==0) c[x]/=3,t[x].s[1]++;
	while(c[x]%5==0) c[x]/=5,t[x].s[2]++;
	while(c[x]%7==0) c[x]/=7,t[x].s[3]++;
	while(c[x]%11==0) c[x]/=11,t[x].s[4]++;
	while(c[x]%13==0) c[x]/=13,t[x].s[5]++;
	if(t[x].son.size()==0) return;
	for(int i=0;i<t[x].son.size();i++) {
		build(t[x].son[i]);
		t[x].s[0]+=t[t[x].son[i]].s[0];
		t[x].s[1]+=t[t[x].son[i]].s[1];
		t[x].s[2]+=t[t[x].son[i]].s[2];
		t[x].s[3]+=t[t[x].son[i]].s[3];
		t[x].s[4]+=t[t[x].son[i]].s[4];
		t[x].s[5]+=t[t[x].son[i]].s[5];
	}
}
int main() {
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	scanf("%d",&n);
	int u,v,x,i;
	for(int i=0;i<n;i++)
		t[i].fa=n+1;
	for(int i=1;i<n;i++) {
		scanf("%d%d",&u,&v);
		t[v].fa=u;
		t[u].son.push_back(v);
	}
	int allfa=findfa();
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);
	build(allfa);
	scanf("%d",&q);
	char s[4];
	while(q--) {
		scanf("%s",s);
		if(s[0]=='R') {
			scanf("%d",&i);
			pair<int,int> qq=query(i);
			printf("%d %d\n",qq.second,qq.first);
		}
		else {
			scanf("%d%d",&u,&x);
			add(u,x);
		}
	}
	return 0;
}
