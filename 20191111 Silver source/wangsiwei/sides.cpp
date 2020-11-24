#include<bits/stdc++.h>
using namespace std;
int t,n,a[10],b[20],at,bt;
int main() {
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	cin>>t;
	while(t--) {
		at=0,bt=0;
		for(int i=1;i<=6;i++) scanf("%d",&a[i]);
		for(int i=1;i<=6;i++) scanf("%d",&b[i]);
		for(int i=1;i<=6;i++) 
			for(int j=1;j<=6;j++) 
				if(a[i]>b[j]) at++;
				else if(a[i]<b[j]) bt++;
		if(at>bt) printf("Alice\n");
		if(at==bt) printf("Tie\n");
		if(at<bt) printf("Bob\n");
	}
	return 0;
}
