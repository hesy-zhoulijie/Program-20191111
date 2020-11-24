#include<bits/stdc++.h>
using namespace std;
int t,a[7],b[7],cnt1=0,cnt2=0;
int main(){
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cnt1=0,cnt2=0; 
		for(int i=0;i<6;i++) scanf("%d",&a[i]);
		for(int i=0;i<6;i++) scanf("%d",&b[i]);
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				if(a[i]>b[i]) cnt1++;
				else if(a[i]<b[i]) cnt2++;
			}
		}
		if(cnt1==cnt2) printf("Tie\n");
		else if(cnt1>cnt2) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}
