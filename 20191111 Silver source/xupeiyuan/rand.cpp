//#include <bits/stdc++.h>
//
//#define MAXN 100010
//#define mod 1000000007//...
//#define ll long long
//
//using namespace std;
//
//int n, u, v, t, q, ans, val, tot;
//int head[MAXN], a[MAXN];
//string s;
//
//struct edge {
//	int to, next;
//}e[MAXN * 2];
//
//void add(int u, int v){
//	e[++tot].to = v;
//	e[tot].next = head[u];
//	head[u] = tot;
//};
//
//ll ask(int x) {
//	val = a[x];
//	for (int i = head[x]; i; i = e[i].next) {
//		val = (val * ask(e[i].to)) % mod;
//	}
//	return val;
//}
//
//ll yin(int x) {
//	val = 0;
//	for (int i = 1; i * i <= x; i++) {
//		if (x % i == 0) val += 2;
//		if (i * i == x) val -= 1;
//	}
//	return val;
//}
//
//int main() {
//	freopen("rand.in", "r", stdin);
//	freopen("rand.out", "w", stdout); 
//	scanf("%d", &n);
//	for (int i = 1; i < n; i++) {
//		scanf("%d%d", &u, &v);
//		add(u + 1, v + 1);
//	}
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &a[i]);
//	}
//	scanf("%d", &q);
//	for (int i = 1; i <= q; i++) {
//		cin >> s >> u;
//		u++;
//		if (s == "RAND") {
//			ans = ask(u) % mod;
//			cout << ans << " " << yin(ans) << endl;
//		}
//		else {
//			cin >> t;
//			a[u] = (a[u] * t) % mod; 
//		}
//	}
//	return 0;
//}
//
//8
//0 1
//0 2
//1 3
//2 4
//2 5
//3 6
//3 7
//7 3 10 8 12 14 40 15
//3
//RAND 1
//SEED 1 13
//RAND 1

#include <bits/stdc++.h>

#define MAXN 100010
#define ll long long
#define mod 1000000007

using namespace std;

int n, q, tot;

ll a[100], ans = 1;
int prime[] = {2, 3, 5, 7, 11, 13}; 
int head[MAXN];

struct edge {
	int next;
	int to;
}e[MAXN];

struct node {
	int val;
	ll su[100];
}s[MAXN];

void add_edge(int x, int y) {
	e[++tot].to = y;
	e[tot].next = head[x];
	head[x] = tot;
}


void build() {
	for (int i = 0; i < n; i++) {
		int t = s[i].val;
		for (int j = 0; j < 6; j++) {
			s[i].su[j] = 0;
			while (t % prime[j] == 0) {
				t /= prime[j];
				s[i].su[j]++;
			}
		}
	}
}

void ask(int x) {
	ans *= s[x].val;
	ans %= mod;
	for (int i = 0; i < 6; i++) {
		a[i] += s[x].su[i];
	}
	for (int i = head[x]; i; i = e[i].next) {
		ask(e[i].to);
	} 
}

void add(int x, int y) {
	s[x].val = (s[x].val * y) % mod;
	for (int i = 0; i < 6; i++) {
		while (y % prime[i] == 0) {
			y /= prime[i];
			s[x].su[i]++;
		}
	}
}

int main() {
	freopen("rand.in", "r", stdin);
	freopen("rand.out", "w", stdout);
	scanf("%d", &n);
	int x, y;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add_edge(x, y);
	}
	for(int i = 0; i < n; ++i) {
		cin>>s[i].val;
	}
		
	build();
	scanf("%d", &q);
	while (q--) {
		int x, y;
		string st;
		cin >> st;
		if (st == "SEED") {
			cin >> x >> y;
			add(x, y);
		}
		else {
			cin >> x;
			a[0] = 1;
			a[1] = 1;
			a[2] = 1;
			a[3] = 1;
			a[4] = 1;
			a[5] = 1;
			ans = 1;
			ask(x);
			ll sum=1;
			for(int i = 0; i < 6; ++i)
				sum = (sum * a[i]) % mod;
			cout << ans << ' ' << sum << endl;
		}
	}
	return 0;
}

