#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> q;
int n,m;
long long ans=0;
int candy[310];
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin>>n>>m;
	int day=1;
	while(day<=n){
		for(int i=0;i<m;i++){
			scanf("%d",&candy[i]);
		}
		sort(candy,candy+m);
		for(int i=0;i<m;i++){
			long long x;
			x=candy[i]+2*(i+1)-1;
			x=-x;
			q.push(x);
		}
		ans-=q.top();
		q.pop();
		day++;
	}
	cout<<ans;
	return 0;
}
