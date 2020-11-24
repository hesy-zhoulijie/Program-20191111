#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300 + 10;
struct node
{
	int weight, day;
}c[MAXN*MAXN];

bool cmp(node x, node y)
{
	return x.weight < y.weight;
}

int n, m, a[MAXN], ans;
bool vis[MAXN*MAXN];

int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d",&a[j]);
		}
		sort(a+1, a+(m+1));
		for (int j = 1; j <= m; j++)
		{
			int tmp = (i-1)*m+j;
			c[tmp].weight = a[j] + 2*j - 1;
			c[tmp].day = i;
		}
	}
	sort(c+1,c+(n*m+1), cmp);
	int left = n;
	for (int i = 1; i <= n*m && left; i++)
	{
		int tmp = c[i].day;
		while (vis[tmp])
			++tmp;
		vis[tmp] = true;
		if (tmp != n+1)
		{
			left--;
			ans += c[i].weight;
		}
	}
	cout << ans << endl;
	return 0;
}
