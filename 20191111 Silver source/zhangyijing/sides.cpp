#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int T;
int a[6],b[6];
int cnt_w,cnt_t;

int main() {
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);	
	
	scanf("%d",&T);
	
	while(T--) {
		cnt_w = 0; cnt_t = 0;
		for(int i = 0; i < 6; i++) {
			scanf("%d",&a[i]);
		}
		for(int i = 0; i < 6; i++) {
			scanf("%d",&b[i]);
			for(int j = 0; j < 6; j++) {
				if(b[i] > a[j]) {
					cnt_w++;
				}
				else if(b[i] == a[j]) {
					cnt_t++;
				}
			}
		}
		int num = 36 - cnt_t;
		cnt_w *= 2;
		if(cnt_w == num) {
			printf("Tie\n");
		}
		else if(cnt_w < num){
			printf("Alice\n");
		}
		else{
			printf("Bob\n");
		}
	}
	
	return 0;
}
