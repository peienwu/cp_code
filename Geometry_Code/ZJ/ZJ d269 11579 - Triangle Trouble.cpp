#include <bits/stdc++.h>
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define ld double
#define N 100001
#define all(x) x.begin(),x.end()
#define eps 1e-9
#define x first
#define y second
using namespace std;
int t,n;
vector<ld> p;

ld area(ld a ,ld b, ld c){
    if(a > b + c)return -1;
    ld p = (a+b+c)/2;
    return p*(p-a)*(p-b)*(p-c);
}

signed main(){
    Orz;
    cin>>t;
    while(t--){
        cin>>n;
        p.assign(n,0);
        rep(i,0,n-1)cin>>p[i];
        sort(all(p),greater<>());
        ld ans = 0;
        rep(i,0,n-3)
            ans = max(ans,area(p[i],p[i+1],p[i+2]));
        cout<<fixed<<setprecision(2);
        cout<<sqrt(ans)<<endl;
    }
}