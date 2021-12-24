#include <bits/stdc++.h>
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define pdd pair<double,double>
#define int long long
#define ll long long
#define ld long double
#define N 100001
#define all(x) x.begin(),x.end()
#define eps 1e-9
#define x first
#define y second

using namespace std;

struct pt{
    int x,y;
    bool operator < (pt b){
        if(x == b.x)return y < b.y;
        return x < b.x;
    }
    bool operator > (pt b){
        if(x == b.x)return y > b.y;
        return x > b.x;
    }
    bool operator == (pt b){
        if(x-b.x == 0 && y-b.y == 0)return true;
        return false;
    }
    pt operator+(pt b) {return {x + b.x, y + b.y};} //向量相加
    pt operator-(pt b) {return {x - b.x, y - b.y};} //向量相減
    int operator^(pt b) {return x * b.y - y * b.x;} //向量外積cross
    int operator*(pt b) {return x * b.x + y * b.y;} //向量內積dot
};

vector<pt> p;
vector<int>  cnt;
int n,edge,ans;

int solve(){
    int area = 0;
    rep(i,0,n-1){
        area += (p[i]^p[i+1]);
        if(p[i].y == p[i+1].y)edge += abs(p[i].x-p[i+1].x);
        if(p[i].x == p[i+1].x)edge += abs(p[i].y-p[i+1].y);
    }
    area = abs(area);
    return area;
}

signed main(){
    Orz;
    cout<<fixed<<setprecision(1);
    while(cin>>n){
        p.assign(n+1,{0,0});
        edge = 0;
        rep(i,0,n-1)cin>>p[i].x>>p[i].y;
        p[n] = p[0];
        ans = solve();
        cout<<ans-((ld)edge/2)<<endl;
    }
}