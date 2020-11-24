#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[305];
long long ans;
int main() {
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	priority_queue<int> q;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) scanf("%d",&a[j]);
		sort(a+1,a+m+1);
		for(int j=1;j<=m;j++) q.push(-1*(j*2-1+a[j]));
		k=q.top();
		q.pop();
		k*=-1;
		ans+=k;
	}
	cout<<ans;
	return 0;
}
