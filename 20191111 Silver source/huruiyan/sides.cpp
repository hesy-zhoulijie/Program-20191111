#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main()
{
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x=0,y=0;
		for(int i=1;i<=6;i++) scanf("%d",&a[i]);
		for(int i=1;i<=6;i++) scanf("%d",&b[i]);
		for(int i=1;i<=6;i++)
		for(int j=1;j<=6;j++)
		{
			if(a[i]<b[j]) x++;
			if(a[i]>b[j]) y++;
		}
		if(x<y) printf("Alice\n");
		if(x>y) printf("Bob\n");
		if(x==y) printf("Tie\n");
	}
	return 0;
}
