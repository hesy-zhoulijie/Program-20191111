#include<bits/stdc++.h>
using namespace std;
int P[6]={2,3,5,7,11,13};
struct NODE{
	int val;
	int fa;
	int primes[8];
	int Si[8];
};
NODE node[100010];
void dcp(int num){
	for(int i=0;i<=5;i++)
		while(node[num].val%P[i]==0)
			node[num].primes[i]++,node[num].val/=P[i],node[num].Si[i]++;
}
void add(int num,int now){
	for(int i=0;i<=5;i++){
		node[now].Si[i]+=node[num].primes[i];
	}
	if(now!=0) add(num,node[now].fa);
}
int main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<=n+5;i++){
		for(int j=0;j<=6;j++){
			node[i].Si[j]=0;
		}
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		node[v].fa=u;
	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		node[i].val=x;
		dcp(i);
	}
	for(int i=1;i<n;i++){
		add(i,node[i].fa);
	}
	int q;
	cin>>q;
	string S,R;
	S="SEED";
	R="RAND";
	while(q){
		q--;
		string str;
		cin>>str;
		if(str==S){
			int u,x;
			scanf("%d%d",&u,&x);
			node[u].val*=x;
			dcp(u);
			if(u) add(u,node[u].fa);
		}
		else{
			int u;
			scanf("%d",&u);
			unsigned long long ans1,ans2;
			ans1=1;
			ans2=1;
			for(int i=0;i<=5;i++){
				for(int j=1;j<=node[u].Si[i];j++){
					ans1*=P[i];
				}
				ans2*=(node[u].Si[i]+1);
			}
			printf("%lld %lld\n",ans1,ans2);
		}
	}
	return 0;
}
