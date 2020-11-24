#include<bits/stdc++.h>
using namespace std;
#define debug 1

long T;
long a[7],b[7];

int main() {
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	
	scanf("%ld",&T);
	register long i,j,A,B;
	long a_win;
	
	for(i=1;i<=T;++i) {
		for(j=0;j<6;++j)
			scanf("%ld",&a[j]);
		for(j=0;j<6;++j)
			scanf("%ld",&b[j]);
		a_win=0;
		
		for(A=0;A<6;++A)
			for(B=0;B<6;++B) {
				if(a[A]>b[B])
					++a_win;
				else if(a[A]<b[B])
					--a_win;
				else;
			}
		
		if(a_win>0) printf("Alice\n");
		else if(a_win==0) printf("Tie\n");
		else printf("Bob\n");
	}
	return 0;
}
