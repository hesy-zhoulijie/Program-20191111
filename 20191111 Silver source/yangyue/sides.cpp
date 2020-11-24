#include <bits/stdc++.h>
using namespace std;
int a[10],b[10];
int N;
short I,J,A,B;
int main(){
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	cin>>N;
	while(N--){
		A=0,B=0,I=1,J=1;
		for(register int i=1;i<=6;++i) cin>>a[i];
		for(register int i=1;i<=6;++i) cin>>b[i];
		while(!((I==7)||(A>18||B>18))){
			if(a[I]>b[J]) A++;
			if(a[I]<b[J]) B++;
			if(J==6)J=1;
			else J++;
			if(J==1) I++;
		}
		if(A>B) cout<<"Alice\n";
		else if(A<B) cout<<"Bob\n";
		else cout<<"Tie\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
