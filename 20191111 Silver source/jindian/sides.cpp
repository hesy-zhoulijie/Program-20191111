#include<bits/stdc++.h>
using namespace std;
int bobcnt,alicecnt;
int alice[10],bob[10];
int main(){
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		t--;
		for(int i=1;i<=6;i++)
			scanf("%d",&alice[i]);
		for(int i=1;i<=6;i++)
			scanf("%d",&bob[i]);
		alicecnt=0;
		bobcnt=0;
		for(int i=1;i<=6;i++)
			for(int j=1;j<=6;j++){
				if(alice[i]>bob[i]) alicecnt++;
				if(bob[i]>alice[i]) bobcnt++;
			}
		if(alicecnt>bobcnt) printf("Alice");
		if(bobcnt>alicecnt) printf("Bob");
		if(bobcnt==alicecnt) printf("Tie");
		printf("\n");
	}
	return 0;
}
