#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	int n;scanf("%d",&n);
	for(int t=1;t<=n;t++)
	{
		int bob=0,ali=0;
		int a[10],b[10];
		for(int i=1;i<=6;i++)	scanf("%d",&a[i]);
		for(int i=1;i<=6;i++)	scanf("%d",&b[i]);
		for(int i=1;i<=6;i++)
			for(int j=1;j<=6;j++)
			{
				if(a[i]>b[j])	bob++;
				if(a[i]<b[j])	ali++;
			}
		if(bob>ali)	cout<<"Alice"<<endl;
		if(bob<ali)	cout<<"Bob"<<endl;
		if(bob==ali)	cout<<"Tie"<<endl;
	}
	
	return 0;
}
