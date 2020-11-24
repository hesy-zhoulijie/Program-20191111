#include<bits/stdc++.h>
using namespace std;
struct pr{
	long long p[305];
}c[305];
long long n,m,ans=0,f,k[305];
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i].p[j];
		}
		sort(c[i].p+1,c[i].p+m+1);
	}
	k[1]=1;
	f=1;
	ans+=c[1].p[1]+1;
	while(f<n){
		long long an,fn;
		an=99999999;
		for(int i=1;i<=f+1;i++){
			if(k[i]<m&&an>c[i].p[k[i]+1]+2*k[i]+1){
				an=c[i].p[k[i]+1]+2*k[i]+1;
				k[i]++;
				fn=i;
			}
		}
		ans+=an;
		k[fn]++;
		f++; 
	}
	cout<<ans<<endl;
	return 0;
}
