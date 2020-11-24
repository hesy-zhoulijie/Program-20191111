#include<bits/stdc++.h>
using namespace std;
int i,j,n,k,m,c[301][301],ans=1e9;
void dfs(int nn,int nm,int p,int lb,int hb){
	printf("%d %d %d %d %d\n",nn,nm,p,lb,hb);
	if(nn==n&&nm==m) {
		ans=min(ans,p);
		return;
	}
	if(p>ans) return;
	if(nm<m){
		if(lb) {
			dfs(nn,nm+1,p-(nm-1)*(nm-1)+c[nn][nm]+(nm)*(nm),1,hb+1);
			dfs(nn,nm+1,p,0,hb);
		}
		else {
			dfs(nn,nm+1,p,0,hb);
		}
	}
	else {
		if(lb){
			if(hb>=0) dfs(nn+1,1,p-(nm-1)*(nm-1)+c[nn][nm]+(nm)*(nm),1,hb);
			if(hb>0) dfs(nn+1,1,p,1,hb-1);
		}
		else{
			if(hb>0) dfs(nn+1,1,p,1,hb-1);
		}
	}
}
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++) scanf("%d",&c[i][j]);
	dfs(1,1,0,1,-1);
	printf("%d",ans);
	return 0;
}
