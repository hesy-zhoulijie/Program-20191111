#include <bits/stdc++.h>
using namespace std;
/*int read()        
{        
    int s = 0, f = 1;        
    char ch = getchar();        
    while(!isdigit(ch)) {        
        if(ch == '-') f = -1;        
        ch = getchar();        
    }        
    while(isdigit(ch)) {        
        s = s * 10 + ch - '0';        
        ch = getchar();        
    }        
    return s * f;        
}       */

int main()
{
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int a[7],b[7];
		for(int j=1;j<=6;j++)
		{
			cin>>a[j];//=read();
		}
		//sort(a+1,a+1+6);
		for(int k=1;k<=6;k++)
		{
			cin>>b[k];//=read();
		}
		
		
		int awin=0,bwin=0;
		for(int p=1;p<=6;p++)
		{
			for(int q=1;q<=6;q++)
			{
				if(a[p]>b[q]) awin++;
				else if(a[p]==b[q]) awin++,bwin++;
				else bwin++;
			}
		}
		//cout<<awin<<' '<<bwin<<endl;
		if(awin<bwin) cout<<"Bob"<<endl;
		else if(awin>bwin) cout<<"Alice"<<endl;
		else if(awin==bwin) cout<<"Tie"<<endl;
	}
	return 0;
}
/*
2
3 3 3 3 3 3
1 1 4 4 4 4
1 2 3 4 5 6
6 5 4 3 2 1
*/
