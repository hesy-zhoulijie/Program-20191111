#include <bits/stdc++.h>
using namespace std;
#define al sides[0]
#define bo sides[1]
int sides[3][6];
int Al = 0, Bo = 0;
class dice
{
	/*
side[0] : dice of Alice
side[1] : dice of Bob
	*/

private:
public:
	static void input()
	{
#ifdef DEBUG
		cout
			<< "Enter function input\n";
#endif
		for (int i = 0; i < 6; i++)
		{
			cin >> al[i];
		}
		for (int i = 0; i < 6; i++)
		{
			cin >> bo[i];
		}
#ifdef DEBUG
		for (int i = 0; i < 6; i++)
		{
			cout << i << " " << al[i] << " " << bo[i] << endl;
			printf("************************************************\n");
		}
#endif
	}
	static bool special_test()
	{
		bool flg = 1;
		for (int i = 0; i < 6; i++)
		{
			if (al[i] != bo[i])
			{
				flg = 0;
#ifdef DEBUG
				cout << i << " " << al[i] << " " << bo[i] << " " << flg << endl;
#endif
			}
		}
		return flg;
	}
	static void sweepy()
	{
#ifdef DEBUG
		cout
			<< "Enter function sweepy\n";
#endif
		for (int i = 0; i < 6; i++)
			al[i] = 0;
		for (int i = 0; i < 6; i++)
			bo[i] = 0;

		input();
		sort(al, al + 6);
		sort(bo, bo + 6);
		compare();
	}
	static void compare()
	{
		if (special_test())
		{
			cout << "Tie\n";
			return;
		}
#ifdef DEBUG
		cout << "Enter function compare\n";
#endif
		for (int i = 0; i < 6; i++)
		{
#ifdef DEBUG
			cout
				<< "Enter function loop cmp\n";
#endif
			if (al[i] >= bo[i])
				Al++;
			if (al[i] <= bo[i])
				Bo++;
#ifdef DEBUG
			cout << i << " " << al[i] << " " << bo[i] << " " << Al << " " << Bo << endl;
#endif
		}
#ifdef DEBUG
		cout
			<< "Enter function print\n";
#endif
		if (Al > Bo)
			cout
				<< "Alice\n";
		else if (Al < Bo)
			cout
				<< "Bob\n";
		else
			cout << "Tie\n";
	}
};
int main()
{
	int n;
	cin >> n;
	for (int loop = 0; loop < n; loop++)
	{
		dice::sweepy();
	}
}