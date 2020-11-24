#include <bits/stdc++.h>

#define MAXN 100010

using namespace std;

int n;

int a[MAXN];
int b[MAXN];

int main() {
	freopen("sides.in", "r", stdin);
	freopen("sides.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 1; i <= 6; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= 6; i++) {
			scanf("%d", &b[i]);
		}
		sort(a + 1, a + 7);
		sort(b + 1, b + 7);
		int sa = 0, sb = 0;
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 6; j++) {
				if (a[i] > b[j]) sa++;
				else if (a[i] < b[j]) sb++;
			}
		}
//		cout << sa << " " << sb << endl;
		if (sa > sb) cout << "Alice\n";
		else if (sa < sb) cout << "Bob\n";
		else cout << "Tie\n";
	}
	return 0;
}

