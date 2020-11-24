#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

/*

构造数据程序 makedata.cpp (makedata)
输入文件 input.txt
你的程序 A.cpp (A  output.txt) 
标准程序（对拍程序） A1.cpp (A1  output1.txt)
检验程序 check.cpp

*/

int main()
{
	int error = 0, times = 1;

	while (++times)
	{
		cout << times << endl;
		if (times == 11)
		{
			cout << times << endl
				 << error << endl;
			return 0;
		}
		system("./makedata");
		system("./A");
		system("./A1");

		if (system("diff output.txt output1.txt"))
		{
			error++;
			// printf("WA!\n");
			// return 0;
		}
		// else
		// printf("YES!\n");
	}
	return 0;
}