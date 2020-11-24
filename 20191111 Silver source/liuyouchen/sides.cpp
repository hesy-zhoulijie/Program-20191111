#include<bits/stdc++.h>
using namespace std;
long long a[11],b[11],T=0;
int main(){
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		for(int j=1;j<=6;j++){
			cin>>a[j];
		}
		for(int j=1;j<=6;j++){
			cin>>b[j];
		}
		sort(a+1,a+7);
		sort(b+1,b+7);
		
/*		for(int j=1;j<=6;j++){
			cout<<a[j];
		}
		cout<<endl;
		for(int j=1;j<=6;j++){
			cout<<b[j];
		}*/
		int w=0,h=1,x=0;;
		double ans=0;
		for(int j=1;j<=6;j++){
			while(a[j]>b[h]&&h<=6){
				x++;
				h++;
			}
			w=h;
			while(a[j]==b[w]&&w<=6){
				ans+=0.5;
				w++;
			}
			ans+=(7-j)*x;
//			cout<<"j="<<j<<"  x="<<x<<"  ans="<<ans<<"  h="<<h<<endl;
			x=0;
		}
		if(ans>18){
			cout<<"Alice"<<endl;
		}
		else if(ans<18){
			cout<<"Bob"<<endl;
		}
		else if(ans=18){
			cout<<"Tie"<<endl;
		}
//		cout<<ans<<endl<<endl;;
	}

	return 0;
}
