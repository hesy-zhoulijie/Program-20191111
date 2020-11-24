#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n, father[MAXN], s[MAXN], weight[MAXN], q;
void change(int u, int x)
{
	s[u] *= x;
	s[u] %= MOD;
	int now = u;
	while (now)
	{
		now = father[now];
		s[now] *= x;
		s[now] %= MOD;
	}
}

void init()
{
	for (int i = 1; i <= n; i++)
	{
		change(i,weight[i]);
	}
}

int query(int q)
{
	int tmp, ans = 1;
	tmp = 1;
	while (q % 2 == 0)
	{
		tmp++;
		q /= 2;
	}
	ans *= tmp;
	tmp = 1;
	while (q % 3 == 0)
	{
		tmp++;
		q /= 3;
	}
	ans *= tmp;
	tmp = 1;
	while (q % 5 == 0)
	{
		tmp++;
		q /= 5;
	}
	ans *= tmp;
	tmp = 1;
	while (q % 7 == 0)
	{
		tmp++;
		q /= 7;
	}
	ans *= tmp;
	tmp = 1;
	while (q % 11 == 0)
	{
		tmp++;
		q /= 11;
	}
	ans *= tmp;
	tmp = 1;
	while (q % 13 == 0)
	{
		tmp++;
		q /= 13;
	}
	ans *= tmp;
	return ans;
}

int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	
	cin >> n;
	int u, v;
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		father[v] = u;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &weight[i]);
		s[i] = 1;
	}
	init();
	cin >> q;
	string com;
	int x;
	for (int i = 1; i <= q; i++)
	{
		cin >> com;
		if (com == "SEED")
		{
			scanf("%d%d", &u, &x);
			change(u,x);
		}
		else
		{
			cin >> x;
			cout << s[x] << " " << query(s[x]) << endl;
		}
	}
	return 0;
}
