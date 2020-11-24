#include <bits/stdc++.h>
using namespace std;
long long a[6],b[6];
int main(){
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	int t,aw=0,bw=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int i=0;i<6;i++) cin>>a[i];
		for(int i=0;i<6;i++){
			cin>>b[i];
			for(int j=0;j<6;j++){
				if(a[j]>b[i]) aw++;
				if(a[j]<b[i]) bw++;
			}
		} 
		if(aw>bw) cout<<"Alice"<<endl;
		else if(aw==bw) cout<<"Tie"<<endl;
		else cout<<"Bob"<<endl;
		aw=0,bw=0;
	}
}
/*
2
3 3 3 3 3 3
1 1 4 4 4 4
1 2 3 4 5 6
6 5 4 3 2 1
*/
