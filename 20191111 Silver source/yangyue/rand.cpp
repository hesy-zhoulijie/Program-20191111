#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#define int long long
#define MOD 1000000007
using namespace std;
int N,Q;
int ksm(int x,int y){
	y%=(MOD-1);
    int aaa=1,bbb=x;
    while(y>0){
        if(y&1){aaa=aaa*bbb;aaa=aaa%MOD;}
        bbb=bbb*bbb;
        bbb=bbb%MOD;
        y=y/2;
    }
    return aaa%MOD;
}
struct V{
	V(){memset(div,0,sizeof(div));}
	int div[10];
	friend V operator + (V x,V y){
		V ans;
		for(int i=1;i<=6;i++) ans.div[i]=x.div[i]+y.div[i];
		return ans;
	}
	friend bool operator == (V x,V y){
		for(int i=1;i<=6;i++) if(x.div[i]!=y.div[i]) return false;
		return true;
	}
};
struct U{
	U(){fa=0;sn.clear();}
	int fa;
	vector<int> sn;
	V div;
	V son;
}a[100005];
inline void ADD(V &x,int y){
	while(!(y&1)) y/=2,x.div[1]++;
	while(!(y%3)) y/=3,x.div[2]++;
	while(!(y%5)) y/=5,x.div[3]++;
	while(!(y%7)) y/=7,x.div[4]++;
	while(!(y%11)) y/=11,x.div[5]++;
	while(!(y%13)) y/=13,x.div[6]++;
	return;
}
inline void ADD2(int x,int y){
	ADD(a[x].son,y);
	ADD(a[x].div,y);
	if(a[x].fa!=0) ADD2(a[x].fa,y);
	return;
}
inline int get_div(V x){
	int anss=1;
	for(register int i=1;i<=6;++i){
		anss=(anss*(x.div[i]+1))%MOD;
	}
	return anss%MOD;
}
inline get_all(V x){
	int anss=1;
	anss*=ksm(2,x.div[1]);anss%=MOD;
	anss*=ksm(3,x.div[2]);anss%=MOD;
	anss*=ksm(5,x.div[3]);anss%=MOD;
	anss*=ksm(7,x.div[4]);anss%=MOD;
	anss*=ksm(11,x.div[5]);anss%=MOD;
	anss*=ksm(13,x.div[6]);anss%=MOD;
	return anss;
}
void prt(V x){
	for(int i=1;i<=6;++i) cout<<x.div[i]<<' ';
	cout<<endl;
}
void ADD3(int x){
	if(a[x].fa==0) return;
	a[a[x].fa].son=a[x].son+a[a[x].fa].son;
	ADD3(a[x].fa);
	return;
}
V ADD4(int x){
	if(a[x].sn.empty()) return a[x].son;
	if(!(a[x].son==a[x].div)) return a[x].son;
	for(int i=0;i<a[x].sn.size();++i) a[x].son=a[x].son+ADD4(a[x].sn[i]);
	return a[x].son;

}
int u,v;
string str;
signed main(){
	freopen("sides.in","r",stdin);
	freopen("sides.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for(register int i=1;i<N;++i){
		cin>>u>>v;++u;++v;
		a[v].fa=u;
		a[u].sn.push_back(v);
	}
	for(register int i=1;i<=N;++i){
		cin>>u;
		ADD(a[i].div,u);
		ADD(a[i].son,u);
	}
	int root=rand()%N;
	while(a[root].fa!=0) root=a[root].fa;
	a[root].son=ADD4(root);
	cin>>Q;
	while(Q--){
		cin>>str;
		if(str=="SEED"){
			cin>>u>>v;++u;
			ADD(a[u].div,v);
			ADD(a[u].son,v);
			ADD2(a[u].fa,v);
		}
		else{
			cin>>u;++u;
			cout<<get_all(a[u].son)<<' ';
			cout<<get_div(a[u].son)<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
