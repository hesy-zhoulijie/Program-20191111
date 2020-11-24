#include<bits/stdc++.h>

using namespace std;

long long t;
long long a[7],b[7];
long long cnt1,cnt2;

int main()
{
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	cin.sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		for(long long i=1;i<=6;i++)
		{
			cin>>a[i];
		}
		for(long long i=1;i<=6;i++)
		{
			cin>>b[i];
		}
		cnt1=0;
		cnt2=0;
		for(long long i=1;i<=6;i++)
		{
			for(long long j=1;j<=6;j++)
			{
				if(a[j]>b[i])cnt1++;
				if(b[i]>a[j])cnt2++;
			}
		}
		if(cnt1>cnt2)cout<<"Alice"<<endl;
		if(cnt1==cnt2)cout<<"Tie"<<endl;
		if(cnt1<cnt2)cout<<"Bob"<<endl;
	}
	
	return 0;
}
