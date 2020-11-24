#include <bits/stdc++.h>

#define MAXN 310

using namespace std;

int n, m;

int a[MAXN][MAXN], sum[MAXN][MAXN];

int f[MAXN][MAXN];

void test_for_f () {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
}

void test_for_sum () {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cout << sum[i][j] << ' ';
		}
		cout << endl;
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = 2100000;
		}
	}
}

int main() {
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i] + 1, a[i] + m + 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
		for (int j = 1; j <= m; j++) {
			sum[i][j] += j * j;
			f[i][j] = sum[i][j];
		}
		for (int j = m + 1; j <= n; j++) f[i][j] = 2100000;
	}
//	test_for_sum();
//	init();
//	test_for_f();
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= min(n, i * m); j++) {
			for (int k = i - 1; k < j; k++) {
//				if (i == 5 && j == 5) cout << "YES" << endl;
				if (j >= n) f[i][j] = min(f[i][j], f[i - 1][j]);
				f[i][j] = min(f[i][j], f[i - 1][k] + sum[i][j - k]);
			}
		}
	}
//	test_for_f();
	int ans = f[n][n];
	for (int i = n + 1; i <= m; i++) {
		ans = min(ans, f[n][i]);
	}
	cout << ans << endl;
	return 0;
}
