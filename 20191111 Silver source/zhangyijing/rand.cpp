#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9+7;

struct node {
	int prev;
	vector<int> next;
} p[N];
int t[N];

struct prime_num{
	int nu[6];
} num[N];

int s[N];
int n,q;
bool processed[N] = {false};
int nnu[6] = {0};

int seperate(int i) {
	int number = t[i];
	int cnt = 0;
	while(number % 2 != 0) {
		cnt++;
		number/=2;
	}
	num[i].nu[0] = cnt;
	
	cnt = 0;
	while(number % 3 != 0) {
		cnt++;
		number/=3;
	}
	num[i].nu[1] = cnt;
	
	cnt = 0;
	while(number % 5 != 0) {
		cnt++;
		number/=5;
	}
	num[i].nu[2] = cnt;
	
	cnt = 0;
	while(number % 7 != 0) {
		cnt++;
		number/=7;
	}
	num[i].nu[3] = cnt;
	
	cnt = 0;
	while(number % 11 != 0) {
		cnt++;
		number/=11;
	}
	num[i].nu[4] = cnt;
	
	cnt = 0;
	while(number % 13 != 0) {
		cnt++;
		number/=13;
	}
	num[i].nu[5] = cnt;
}

int seperate2(int x) {
	int number = x;
	int cnt = 0;
	while(number % 2 != 0) {
		cnt++;
		number/=2;
	}
	nnu[0] = cnt;
	
	cnt = 0;
	while(number % 3 != 0) {
		cnt++;
		number/=3;
	}
	nnu[1] = cnt;
	
	cnt = 0;
	while(number % 5 != 0) {
		cnt++;
		number/=5;
	}
	nnu[2] = cnt;
	
	cnt = 0;
	while(number % 7 != 0) {
		cnt++;
		number/=7;
	}
	nnu[3] = cnt;
	
	cnt = 0;
	while(number % 11 != 0) {
		cnt++;
		number/=11;
	}
	nnu[4] = cnt;
	
	cnt = 0;
	while(number % 13 != 0) {
		cnt++;
		number/=13;
	}
	nnu[5] = cnt;
}

void process(int x) {
	if(processed[x]) return;
	
	if(p[x].next.size() == 0) return;
	
	for(int i = 0; i < p[x].next.size(); i++) {
		process(p[x].next[i]);
		num[x].nu[0] += num[p[x].next[i]].nu[0];
		num[x].nu[1] += num[p[x].next[i]].nu[1];
		num[x].nu[2] += num[p[x].next[i]].nu[2];
		num[x].nu[3] += num[p[x].next[i]].nu[3];
		num[x].nu[4] += num[p[x].next[i]].nu[4];
		num[x].nu[5] += num[p[x].next[i]].nu[5];
	}
	processed[x] = true;
	return;
}

void process2(int x) {
	if(p[x].prev == -1) return;
	
	for(int i = 0; i < 6; i++) {
		num[p[x].prev].nu[i] += nnu[i];
	}
	process2(p[x].prev);

	return;
}

int main() {
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	
	scanf("%d",&n);
	
	int x,y;
	for(int i = 0; i < n; i++) {
		scanf("%d%d",&x,&y);
		p[y].prev = x;
		p[x].next.push_back(y);
		p[x].prev = -1;
	}
	
	for(int i = 0; i < n; i++) {
		scanf("%d",&t[i]);
		seperate(i);
	}
	
	for(int i = 0; i < n; i++) {
		process(i);
	}
	
	scanf("%d",&q);
	while(q--) {
		string s;
		cin >> s;
		if(s[0] == 'R') {
			scanf("%d",&x);
			int ans = 1;
			for(int i = 0; i < 6; i++) {
				ans *= (num[x].nu[i]+1);
				ans %= MOD;
			}
			ans -= 1;
			printf("%d\n",ans);
		}
		else {
			scanf("%d%d",&x,&y);
			for(int i = 0; i < 6; i++) {
				num[x].nu[i] += nnu[i];
			}
			seperate2(y);
			process2(x);
		}
	}
	
	return 0;
}
