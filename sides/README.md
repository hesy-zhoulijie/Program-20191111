# 骰子的游戏
## 目录

## 题面
在Alice和Bob面前的是两个骰子，上面分别写了六个数字。

Alice和Bob轮流丢掷骰子，Alice选择第一个骰子，而Bob选择第二个，如果谁投掷出的数更大，谁就可以获胜。

现在给定这两个骰子上的6个数字，你需要回答是Alice获胜几率更大，还是Bob获胜几率更大。（请注意获胜几率相同的情况）

输入描述:
> 第一行一个数T，表示数据个数。
> 接下来的每一组数据一共有2行，每一行有6个正整数，第一行是第一个骰子上的6个数，第二行是第二个骰子上的6个数。

输出描述:
> 如果Alice获胜几率更大，你需要输出Alice；
> 如果Bob获胜几率更大，你需要输出Bob；
> 如果获胜几率一样大，你需要输出Tie。
```
示例1
输入
2
3 3 3 3 3 3
1 1 4 4 4 4
1 2 3 4 5 6
6 5 4 3 2 1
输出
Bob
Tie
说明
第一个数据中，Alice有三分之一几率获胜，Bob有三分之二几率获胜；
第二个数据中，Alice和Bob的骰子完全一致，所以获胜几率一样大。
```
## 结果

1. 在随机数据上总分$\lfloor\dfrac{18.19'+43.57'+43.9'}3\rfloor≈35'$
2. 在10以内的数据上总分$43.9'$
3. 在100以内的数据上总分$43.57'$
4. 在100以内的数据上总分$18.19'$

## $\rm\boxed{\color{orange}Code}$
### My Code
```cpp
/*
在10组数据，每个数据在1000以内的随机数据：18.19
在100组数据，每个数据在100以内的随机数据：43.57
在1000组数据，每个数据在10以内的随机数据：43.9

*/
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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int loop = 0; loop < n; loop++)
	{
		dice::sweepy();
	}
}
```

### `std`
```cpp
#include <bits/stdc++.h>
using namespace std;
int T, cnt1, cnt2;
int a[10], b[10];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 1; i <= 6; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= 6; i++)
			scanf("%d", &b[i]);
		cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= 6; i++)
			for (int j = 1; j <= 6; j++)
			{
				if (a[i] > b[j])
					++cnt1;
				if (a[i] < b[j])
					++cnt2;
			}
		if (cnt1 > cnt2)
			printf("Alice\n");
		else if (cnt1 < cnt2)
			printf("Bob\n");
		else
			printf("Tie\n");
	}
	return 0;
}

```

## 题解

我们直接暴力枚举出$6*6$的每一种情况，然后判断$a[i]>b[j], a[i]<b[j]$的情况数
量，分别讨论两种情况哪个更多，然后直接输出即可。
需要注意一下相等的情况，else的那一句 需要小心易下。
时间复杂度$\mathrm O(1)$,期望得分100分。
