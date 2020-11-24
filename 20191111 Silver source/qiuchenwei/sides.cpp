#include<bits/stdc++.h>
using namespace std;
int T,a[6],b[6],t;
int win()
{
	int x=0,y=0;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(a[i]>b[j]) x++;
			if(a[i]<b[j]) y++;
		}
	}
	if(x>y) return 1;
	if(x<y) return -1;
	return 0;
}
int main()
{
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<6;j++) cin>>a[j];
		for(int j=0;j<6;j++) cin>>b[j];
		t=win();
		if(t>0) cout<<"Alice"<<endl;
		if(t<0) cout<<"Bob"<<endl;
		if(t==0) cout<<"Tie"<<endl;
	}
	return 0;
}
