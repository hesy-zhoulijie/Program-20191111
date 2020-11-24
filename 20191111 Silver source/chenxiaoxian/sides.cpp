#include <bits/stdc++.h>

using namespace std;

int a[6],b[6];

int main()
{
	int t,cnt1,cnt2;
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cnt1=cnt2=0;
		for(int i=0;i<6;i++)
			cin>>a[i];
		for(int i=0;i<6;i++)
			cin>>b[i];
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
			{
				if(a[i]>b[j])
					cnt1++;
				if(a[i]<b[j])
					cnt2++;
			}
		if(cnt1>cnt2)
			cout<<"Alice"<<endl;
		else if(cnt1<cnt2)
			cout<<"Bob"<<endl;
		else
			cout<<"Tie"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
