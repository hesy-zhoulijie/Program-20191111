#include<bits/stdc++.h>
using namespace std;
//#define debug 1

const long MAXN=100010;
long n,query_num,fa[MAXN];
long divide[MAXN][6];
/*
divide[i][0] -> 2 num
		 [1] -> 3
		 [2] -> 5
		 [3] -> 7
		 [4] -> 11
		 [5] -> 13
*/

long now_div[6];
void DIVIDE_NUM(long a) {
	memset(now_div,0,sizeof(now_div));
	while(a%2==0) ++now_div[0],a/=2;
	while(a%3==0) ++now_div[1],a/=3;
	while(a%5==0) ++now_div[2],a/=5;
	while(a%7==0) ++now_div[3],a/=7;
	while(a%11==0) ++now_div[4],a/=11;
	while(a%13==0) ++now_div[5],a/=13;
}

const long long mod=1000000009;
long long fast_mod(long long a,long long b) {
	if(b==0) return 1;
	if(b==1) return a;
	long long power=fast_mod(a,b/2);
	if(b%2==0)
		return power*power%mod;
	else
		return (power*power%mod)*a%mod;
}

int main() {
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	scanf("%ld",&n);
	register long i;
	long u_input,v_input,T_input;
	for(i=1;i<n;++i) {
		scanf("%ld%ld",&u_input,&v_input);
		//	if(fa[v]!=0)
		//	printf("rand.exe: fatal error: Invalid input data\n");
		fa[v_input]=u_input;
	}
	for(i=0;i<n;++i) {
		scanf("%ld",&T_input);
		DIVIDE_NUM(T_input);
		long u=i;
		while(u!=0) {
				divide[u][0]+=now_div[0];
				divide[u][1]+=now_div[1];
				divide[u][2]+=now_div[2];
				divide[u][3]+=now_div[3];
				divide[u][4]+=now_div[4];
				divide[u][5]+=now_div[5];
#ifdef debug
				printf("CHANGE ");
				printf("num[%ld]={",u);
				for(long j=0;j<6;++j)
					printf("%ld ",divide[i][j]);
				printf("}\n");
#endif
				u=fa[u];
			}
			divide[u][0]+=now_div[0];
			divide[u][1]+=now_div[1];
			divide[u][2]+=now_div[2];
			divide[u][3]+=now_div[3];
			divide[u][4]+=now_div[4];
			divide[u][5]+=now_div[5];
#ifdef debug
			printf("CHANGE ");
			printf("num[%ld]={",u);
			for(long j=0;j<6;++j)
				printf("%ld ",divide[i][j]);
			printf("}\n");
#endif
	}
	
#ifdef debug
	printf("DIVIDE:\n");
	for(long i=0;i<n;++i) {
		printf("num[%ld]={",i);
		for(long j=0;j<6;++j)
			printf("%ld ",divide[i][j]);
		printf("}\n");
	}
#endif
	scanf("%ld",&query_num);
	char c;
	long u,x;
	bool is_SEED;
	for(i=0;i<query_num;++i) {
		c=getchar();
		while(c<'A' || c>'Z') c=getchar();
		if(c=='S') {
			scanf("EED %ld %ld",&u,&x);
			DIVIDE_NUM(x);
			while(u!=0) {
				divide[u][0]+=now_div[0];
				divide[u][1]+=now_div[1];
				divide[u][2]+=now_div[2];
				divide[u][3]+=now_div[3];
				divide[u][4]+=now_div[4];
				divide[u][5]+=now_div[5];
#ifdef debug
				printf("CHANGE ");
				printf("num[%ld]={",u);
				for(long j=0;j<6;++j)
					printf("%ld ",divide[i][j]);
				printf("}\n");
#endif
				u=fa[u];
			}
			divide[u][0]+=now_div[0];
			divide[u][1]+=now_div[1];
			divide[u][2]+=now_div[2];
			divide[u][3]+=now_div[3];
			divide[u][4]+=now_div[4];
			divide[u][5]+=now_div[5];
#ifdef debug
			printf("CHANGE ");
			printf("num[%ld]={",u);
			for(long j=0;j<6;++j)
				printf("%ld ",divide[i][j]);
			printf("}\n");
#endif
		}
		else {
			scanf("AND %ld",&u);
			long long ans1=1;
			ans1=fast_mod(2,divide[u][0]);
			ans1*=fast_mod(3,divide[u][1]);
			ans1%=mod;
			ans1*=fast_mod(5,divide[u][2]);
			ans1%=mod;
			ans1*=fast_mod(7,divide[u][3]);
			ans1%=mod;
			ans1*=fast_mod(11,divide[u][4]);
			ans1%=mod;
			ans1*=fast_mod(13,divide[u][5]);
			ans1%=mod;
			printf("%lld ",ans1);
			long long ans2=1;
			ans2=divide[u][0]+1;
			ans2*=(long long)(divide[u][1]+1);
			ans2%=mod;
			ans2*=(long long)(divide[u][2]+1);
			ans2%=mod;
			ans2*=(long long)(divide[u][3]+1);
			ans2%=mod;
			ans2*=(long long)(divide[u][4]+1);
			ans2%=mod;
			ans2*=(long long)(divide[u][5]+1);
			ans2%=mod;
			printf("%lld\n",ans2);
		}
	}
	return 0;
}
