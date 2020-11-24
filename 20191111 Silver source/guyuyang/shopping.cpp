#include<bits/stdc++.h>
#define maxn 400
using namespace std;
int a[400][400];
int b[400];
int main()
{
   freopen("shopping.in","r",stdin);
   freopen("shopping.out","w",stdout);
   int n,m;
   cin>>n>>m;
   for(int j=1;j<=n;j++)
   {
      for(int k=1;k<=m;k++)
	  {
         cin>>a[j][k];
      }
      sort(a[j]+1,a[j]+1+m);
      for(int k=1;k<=m;k++)
	  {
         a[j][k]+=2*k-1;
      }
   }
   long long sum=0;
   memset(b,0,sizeof(b));
   for(int j=1;j<=n;j++)
   {
      long long min=1e18;
      int z=0;
      for(int k=1;k<=j;k++)
	  {
          if(b[k]==m) continue;
          if(a[k][b[k]+1]<min)
		  {
             min=a[k][b[k]+1];
             z=k;
          }
      }
      sum+=min;
      b[z]++;
   }
   cout<<sum<<endl;
   return 0;
}
