#include <bits/stdc++.h>
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pdd pair<double,double>
#define int long long
#define ld long double
#define N 15
#define x first
#define y second
using namespace std;

int n;
pdd p[N];

ld check(pdd a, pdd b){
    return a.x*b.y - a.y*b.x;
}

signed main(){
    Orz;
    while(cin>>n){
        rep(i,0,n-1)cin>>p[i].x>>p[i].y;
        p[n] = p[0];
        ld area = 0.0;
        rep(i,0,n-1)area += check(p[i],p[i+1]);
        ld ans = (ld)area/2;
        if(ans<0)ans = -ans;
        cout<<fixed<<setprecision(2);
        cout<<ans<<endl;
    }
}