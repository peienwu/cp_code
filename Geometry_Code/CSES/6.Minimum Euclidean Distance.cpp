#include <bits/stdc++.h>
#define int long long
#define N 200005
#define x first
#define y second
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int n;
vector<pii> p;

int dis(pii a,pii b){
    int x = a.x - b.x,y = a.y - b.y;
    return x * x + y * y;
}

signed main(){
    IOS;
    cin>>n;
    p.assign(n,{0,0});
    for(int i = 0;i < n;i++)cin>>p[i].x>>p[i].y;
    sort(p.begin(),p.end());
    set<pii> s = {{p[0].y,p[0].x}};
    int l = 0,ans = LONG_LONG_MAX;
    for(int i = 1;i < n;i++){
        int d = ceil(sqrt(ans));
        while(l < i && p[l].x < p[i].x - d){
            s.erase({p[l].y,p[l].x});
            l++;
        }
        auto it_l = s.lower_bound({p[i].y - d,0});
        auto it_r = s.upper_bound({p[i].y + d,0});
        for(auto it = it_l;it != it_r;it++){
            ans = min(ans,dis({it->y,it->x},p[i]));
        }
        s.insert({p[i].y,p[i].x});
    }
    cout<<ans<<endl;
}

