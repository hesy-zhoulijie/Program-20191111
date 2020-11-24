#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int a[100010],b[100010],ans=0;
		for(int j=1;j<=6;j++)	cin>>a[j];
		for(int j=1;j<=6;j++)	cin>>b[j];
		for(int j=1;j<=6;j++)
			for(int k=1;k<=6;k++)
			{
				if(a[j]>b[k])	ans++;
				else if(a[j]<b[k])	ans--;
			}
		if(ans<0)	cout<<"Bob"<<endl;
		else if(ans==0)	cout<<"Tie"<<endl;
		else if(ans>0)	cout<<"Alice"<<endl;
	}
}
