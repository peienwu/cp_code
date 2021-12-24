#include <bits/stdc++.h>
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define rep(i,a,b) for(int i=a,i<=b;i++)
#define rep2(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define pdd pair<double,double>
#define int long long
#define ll long long
#define ld long double
#define N 1003
#define eps 1e-9
#define x first
#define y second
using namespace std;
int n;
pii p[N];

int dist(pii a,pii b){
    int x = a.x-b.x,y = a.y-b.y;
    return x*x+y*y;
}

signed main(){
    Orz;
    cin>>n;
    rep2(i,0,n)cin>>p[i].x>>p[i].y;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dis = dist(p[i],p[j]);
            mp[dis]+=1;
        }
    }
    int ans = 0;
    for(auto i:mp){
        int cnt = i.second;
        ans+=((cnt*(cnt-1))/2);
    }
    cout<<ans<<endl;
}