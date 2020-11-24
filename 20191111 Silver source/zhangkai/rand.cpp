#include<bits/stdc++.h>
using namespace std;
vector<int> G[100005];
vector<int> GF[100005];
int sum[100005];
int much[100005][6];
int zhi[6]={2,3,5,7,11,13};
int first[6]; 
const int mod=1000000007;
int node[100005];
void modify(int now,int w){
	if(now==0){
		return ;
	}
	for(int i=0;i<6;i++){
		much[now][i]+=first[i];
	}
	node[now]=node[now]*w%mod;
	modify(GF[now][0],w);
}
void build(int now){
	for(vector<int>::iterator it=G[now].begin();it<G[now].end();it++){
		build(*it);
	}
	for(vector<int>::iterator it=G[now].begin();it<G[now].end();it++){
		node[now]=(node[now]*node[*it])%mod;
		for(int i=0;i<6;i++){
			much[now][i]=(much[now][i]+much[*it][i])%mod;
		}
	}
}
int main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	int n;
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		GF[v].push_back(u);
	}
	long long tmp;
	for(int i=0;i<n;i++){
		scanf("%d",&node[i]);
		tmp=node[i];
		for(int j=0;j<6;j++){
			while(tmp%zhi[j]==0){
				much[i][j]++,tmp/=zhi[j];
			}
		}
	}
	build(0);
	int q;
	scanf("%d",&q);
	char op[10];
	int x,y;
	for(int i=1;i<=q;i++){
		scanf("%s",op);
		if(op[0]=='R'){
			scanf("%d",&x);
			long long ans=1;
			for(int i=0;i<6;i++){
				ans=(ans*(much[x][i]+1))%mod;
			}
			printf("%lld %lld\n",node[x],ans);
		}else if(op[0]=='S'){
			scanf("%d%d",&x,&y);
			int tmp=y;
			memset(first,0,sizeof(first));
			for(int j=0;j<6;j++){
				while(tmp%zhi[j]==0){
					first[j]++,tmp/=zhi[j];
				}
			}
			modify(x,y);
		}
	}
	return 0;
}
/*
8
0 1
0 2
1 3
2 4
2 5
3 6
3 7
7 3 10 8 12 14 40 15
3
RAND 1
SEED 1 13
RAND 1
*/ 
