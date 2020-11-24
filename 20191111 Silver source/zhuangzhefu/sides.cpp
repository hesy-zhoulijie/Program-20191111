#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("sides.in","r",stdin);
    freopen("sides.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;++i)
	{
		int a=0,b=0;
		int alice[10],bob[10];
		for(int j=1;j<=6;++j)
		{
			scanf("%d",&alice[j]);
		}
		for(int k=1;k<=6;++k)
		{
			scanf("%d",&bob[k]);
			if(bob[k]>alice[k])
				++b;
			if(bob[k]<alice[k])
				++a;
		}
		if(a>b)
		{
			cout<<"Alice"<<endl;
		}
		if(a==b)
		{
			cout<<"Tie"<<endl;
		}
		if(a<b)
		{
			cout<<"Bob"<<endl;
		}
	}
	return 0;
}
