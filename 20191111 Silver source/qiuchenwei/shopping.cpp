#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],ans=0;
int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) sort(a+i*m,a+i*m+m);
	for(int i=0;i<n*m;i++) a[i]+=(i%m)*2+1;
	sort(a,a+n*m);
	for(int i=0;i<n;i++) ans+=a[i];
	cout<<ans;
	return 0;
}
