#include<bits/stdc++.h>
using namespace std;
int T,x,y,a[7],b[7];
int main()
{
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        x=0;y=0;
        for(int i=1;i<=6;i++)scanf("%d",&a[i]);
        for(int i=1;i<=6;i++)scanf("%d",&b[i]);
        for(int i=1;i<=6;i++)
            for(int j=1;j<=6;j++)
                if(a[i]>b[j])x++;
                else if(a[i]<b[j])y++;
        if(x>y)puts("Alice");
        if(x<y)puts("Bob");
        if(x==y)puts("Tie");
    }
    return 0;
}
