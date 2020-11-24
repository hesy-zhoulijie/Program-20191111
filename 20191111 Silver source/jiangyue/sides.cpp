#include<bits/stdc++.h>
using namespace std;
int T;
int a[7],b[7];
int main() {
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		for(int i=1;i<=6;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=6;i++)
			scanf("%d",&b[i]);
		int suma=0,sumb=0;
		for(int i=1;i<=6;i++)
			for(int j=1;j<=6;j++) {
				if(a[i]>b[i]) suma++;
				else if(a[i]<b[i]) sumb++;
				else suma++,sumb++;
			}
		if(suma>sumb) printf("Alice\n");
		else if(suma==sumb) printf("Tie\n");
		else printf("Bob\n");
	}
	return 0;
}

