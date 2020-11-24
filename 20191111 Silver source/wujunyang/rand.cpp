#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
const int maxn=1e5+10;
struct Tree{
	int left=-1,down=-1;
	long long val=0,mul=1;
}t[maxn];
void build(int p,int v){
	if(t[p].left<=0) t[p].left=v;
	else build(t[p].left,v);
	return;
}
void search(int p,int r){
	t[r].mul=(t[r].mul*t[p].val)%mod;
	if(t[p].left>=0) search(t[p].left,r);
	if(t[p].down>=0) search(t[p].down,r);
	return;
}
int main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	int n,u,v,q;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		if(t[u].down<=0) t[u].down=v;
		else build(t[u].down,v);
	}
	for(int i=0;i<n;i++) cin>>t[i].val;
	cin>>q;
	string s;
	long long x,sum=0;
	for(int i=1;i<=q;i++){
		cin>>s;
		if(s=="SEED"){
			cin>>u>>x;
			t[u].val=(t[u].val*x)%mod;
		}
		else if(s=="RAND"){
			cin>>u;
			t[u].mul=t[u].val;
			search(t[u].down,u);
			for(int j=1;j<sqrt(t[u].mul);j++){
				if(t[u].mul%j==0) sum=(sum+2)%mod;
			}
			if((long long)sqrt(t[u].mul)*(long long)sqrt(t[u].mul)==t[u].mul) sum++;
			cout<<t[u].mul<<" "<<sum<<endl;
			sum=0;
		}
	}
	return 0;
}
/*
8
0 1
0 2
1 3
2 4
2 5
3 6
3 7
7 3 10 8 12 14 40 15
3
RAND 1
SEED 1 13
RAND 1

10
0 1
0 3
0 5
5 2 
5 6
2 4
6 7 
6 8
0 9
11 7 5 3 1 1 2 10 100 4
5
SEED 6 7
RAND 6 
SEED 6 10
RAND 2
RAND 5
*/
