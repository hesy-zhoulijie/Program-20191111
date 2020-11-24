#include<bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
const long long mod=1e9+7;
const long long xu[6]={2,3,5,7,11,13};
const long long N=100005;
long long n,m,x,y,top,a[N],ans[10],head[N],seg[N],rev[N],size[N];
char s[N];
struct node{
    long long too,next;
}edge[N*2];
struct node2{
    long long jia[10];
}tree[N*4];
long long kuai(long long a,long long b)
{
    if(b==0)return 1;
    if(b==1)return a;
    long long x=kuai(a,b/2);
    if(b%2==0)return x*x%mod;
    return x*x%mod*a%mod;
}
void add(long long a,long long b)
{
    edge[++top].too=b;edge[top].next=head[a];head[a]=top;
}
void dfs(long long u,long long fa)
{
    seg[u]=++seg[0];
    rev[seg[0]]=u;
    size[u]=1;
    for(long long i=head[u];i;i=edge[i].next)
    {
        long long v=edge[i].too;
        if(v==fa)continue;
        dfs(v,u);
        size[u]+=size[v];
    }
}
void pushup(long long nod)
{
    for(long long i=0;i<6;i++)
        tree[nod].jia[i]=(tree[nod*2].jia[i]+tree[nod*2+1].jia[i])%mod;
}
void build(long long nod,long long l,long long r)
{
    if(l==r)
    {
        for(long long i=0;i<6;i++)
        {
            while(a[rev[l]]%xu[i]==0)
            {
                tree[nod].jia[i]++;
                tree[nod].jia[i]%=mod;
                a[rev[l]]/=xu[i];
            }
        }
        return;
    }
    build(nod*2,l,mid);build(nod*2+1,mid+1,r);
    pushup(nod);
}
void change(long long nod,long long l,long long r,long long x,long long val)
{
    if(l==r)
    {
        for(long long i=0;i<6;i++)
        {
            while(val%xu[i]==0)
            {
                tree[nod].jia[i]++;
                tree[nod].jia[i]%=mod;
                val/=xu[i];
            }
        }
        return;
    }
    if(x<=mid)change(nod*2,l,mid,x,val);
    else change(nod*2+1,mid+1,r,x,val);
    pushup(nod);
}
void find(long long nod,long long l,long long r,long long L,long long R)
{
    if(l==L&&r==R)
    {
        for(long long i=0;i<6;i++)ans[i]=(ans[i]+tree[nod].jia[i])%mod;
        return;
    }
    if(R<=mid)find(nod*2,l,mid,L,R);
    else if(L>mid)find(nod*2+1,mid+1,r,L,R);
    else{
        find(nod*2,l,mid,L,mid);
        find(nod*2+1,mid+1,r,mid+1,R);
    }
}
int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        x++;y++;
        add(x,y);
        add(y,x);
    }
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    dfs(1,0);
    build(1,1,n);
    scanf("%lld",&m);
    while(m--)
    {
        scanf("%s",s);
        if(s[0]=='R')
        {
            long long res=1,sum=1;
            scanf("%d",&x);
            x++;
            for(long long i=0;i<6;i++)ans[i]=0;
            find(1,1,n,seg[x],seg[x]+size[x]-1);
            for(long long i=0;i<6;i++)
            {
                res=(long long)res*kuai(xu[i],ans[i])%mod;
                sum=(long long)sum*(ans[i]+1)%mod;
            }
            printf("%lld %lld\n",res,sum);
        }
        else{
            scanf("%lld%lld",&x,&y);
            x++;
            change(1,1,n,seg[x],y);
        }
    }
    return 0;
}
