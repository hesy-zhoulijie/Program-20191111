#include <bits/stdc++.h>
using namespace std;
int c[350][350],f[350][350];
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			cin>>c[i][j];
		}
		sort(c[i],c[i]+m);
		for(int j=1;j<m;j++){
			c[i][j]+=c[i][j-1];
		}
	}
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=min(m*i,n);j++){
			f[i][j]=f[i-1][j];
			if(i==1) f[i][j]=c[i][j-1]+j*j;
			else{
				for(int k=0;k<=m-1;k++){  //k+1:这次取糖数 
					f[i][j]=min(f[i][j],f[i-1][j-k-1]+c[i][k]+(k+1)*(k+1));
				}
					
			}
//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;	
		}
	}
	cout<<f[n][n]<<endl;
	return 0;
}
/*
5 5
1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4
*/
