#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	int n;
	cin>>n;
	int a[6],b[6];
	for(int cas=0;cas<n;cas++){
		for(int i=0;i<6;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<6;i++){
			scanf("%d",&b[i]);
		}
		int cnta=0,cntb=0;
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				if(a[i]>b[j]){
					cnta++;
				}else if(a[i]<b[j]){
					cntb++;
				}
			}
		}
		if(cnta>cntb){
			printf("Alice\n");
		}else if(cnta==cntb){
			printf("Tie\n");
		}else{
			printf("Bob\n");
		}
	}
	return 0;
}
