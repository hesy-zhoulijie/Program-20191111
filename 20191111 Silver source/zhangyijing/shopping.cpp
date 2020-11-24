#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int n,m;
int c[305][305];
int p[305];
int cnt = 0;

int main() {
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	memset(p,0,sizeof(p));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d",&c[i][j]);
		}
		sort(c[i]+1,c[i]+m+1);
		p[i] = 1;
	}
	
	cnt = c[1][1] + 1;
	p[1]++;
	for(int i = 2; i <= n; i++) {
		int cost_min = INF;
		int min_index = 0;
		for(int j = 1; j <= i; j++) {
			if(p[j] > m) continue;
			
			int cost = c[j][p[j]] + p[j]*p[j] - (p[j]-1)*(p[j]-1);
			if(cost < cost_min) {
				cost_min = cost;
				min_index = j;
			}
		}
		cnt += cost_min;
		p[min_index]++;
	}
	
	printf("%d",cnt);
	
	return 0;
}
