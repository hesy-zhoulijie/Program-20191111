#include<bits/stdc++.h>
using namespace std;
const int N=36;
int a[6],b[6],t,ans1=0,ans2=0;

int main()
{	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans1=0,ans2=0;
		for(int i=0;i<6;++i)
			cin>>a[i];
		for(int i=0;i<6;++i)
			cin>>b[i];
		for(int i=0;i<6;++i)
			for(int j=0;j<6;++j)
				if(a[i]==b[j])
					ans2++;
				else if(a[i]>b[j])
					ans1++;
		if(N-ans2>2*ans1)
			cout<<"Bob"<<endl;
		else if(N-ans2==2*ans1)
			cout<<"Tie"<<endl;
		else
			cout<<"Alice"<<endl;
	}
	return 0;
}
