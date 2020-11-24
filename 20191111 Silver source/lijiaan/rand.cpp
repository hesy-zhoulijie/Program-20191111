#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> t[100005];
const ll mod=1e9+7;
ll n,q,v[100005],p[14];
const ll pri[6]={2,3,5,7,11,13};
string s;
ll dfs(ll x,ll ti){
	ll ans=v[x];
	for(ll i=0;i<t[x].size();i++){
		ans*=dfs(t[x][i],ti+1);
		ans%=mod;
	}
	return ans;
}
ll cnt(ll x){
	memset(p,0,sizeof(p));
	ll ans=1;
	while(x!=1){
		for(ll i=0;i<6;i++){
			if(x%pri[i]==0) x/=pri[i],p[pri[i]]++;
		}
	}
	for(int i=0;i<=13;i++){
		ans*=(p[i]+1);
		ans%=mod;
	}
	return ans;
}
int main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=0;i<n-1;i++){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		t[a].push_back(b);
	}
	for(ll i=0;i<n;i++) scanf("%lld",&v[i]);
	scanf("%lld",&q);
	for(ll i=0;i<q;i++){
		cin>>s;
		if(s=="SEED"){
			ll a,x;
			scanf("%lld%lld",&a,&x);
			v[a]*=x;
		}
		else if(s=="RAND"){
			ll x;
			scanf("%lld",&x);
			ll si=dfs(x,0);
			printf("%lld %lld\n",si,cnt(si));
		}
	}
	return 0;
}
