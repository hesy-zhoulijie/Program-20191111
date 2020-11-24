#include<bits/stdc++.h>
using namespace std;

int n, x[7], y[7], ans;


int main()
{
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		ans = 0;
		for (int j = 1; j <= 6; j++)
			scanf("%d",&x[j]);
		for (int j = 1; j <= 6; j++)
			scanf("%d",&y[j]);
		sort(y+1, y+(6+1));
		for (int j = 1; j <= 6; j++)
		{
			int temp = x[j];
			int pos = upper_bound(y+1, y+(6+1), temp) - y;
//			cout << pos << " ";
			if (y[pos-1] == x[j])
				ans += (2*(pos-1) - 1);
			else
				ans += 2*(pos-1);
		}
//		cout << endl;
		if (ans < 36)
			cout << "Bob" << endl;
		if (ans == 36)
			cout << "Tie" << endl;
		if (ans > 36)
			cout << "Alice" << endl;
	}
	return 0;
}
