#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "w", stdout);
	srand(time(0));
	int n = rand() % 10;
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < 12; i++)
		{
			if (i == 7)
				cout << endl;
			cout << rand() % 1000 << " ";
		}
	}
	return 0;
}