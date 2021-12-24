#include <bits/stdc++.h>
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define pdd pair<double,double>
#define int long long
#define ll long long
#define ld long double
#define N 100001
#define eps 1e-9
#define x first
#define y second

using namespace std;

struct pt{
    ld x,y;
    bool operator < (pt b){
        if(x == b.x)return y < b.y;
        return x < b.x;
    }
    bool operator > (pt b){
        if(x == b.x)return y > b.y;
        return x > b.x;
    }
    bool operator == (pt b){
        if(abs(x-b.x)<=eps && abs(y-b.y)<=eps)return true;
        return false;
    }
    pt operator+(pt b) {return {x + b.x, y + b.y};} //向量相加
    pt operator-(pt b) {return {x - b.x, y - b.y};} //向量相減
    ld operator^(pt b) {return x * b.y - y * b.x;} //向量外積cross
    ld operator*(pt b) {return x * b.x + y * b.y;} //向量內積dot
};
bool cmp(pt a, pt b){
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}
vector<pt> p,hull;
int n,t,h;
ld ans;

bool check(pt a,pt b,pt o){
    int cross = (a - o)^(b - o);
    return cross >= 0;                              //這裡很關鍵，別吃WA
}

bool check2(pt a,pt b,pt c,pt d){
    ld aa = (a - c)^(b - c);
    ld bb = (a - d)^(b - d);
    return aa < bb;
}

ld area(pt a,pt b){
    return abs(a^b)/2;
}

void convex_hull(){
    hull.clear();
    sort(p.begin(),p.end(),cmp);       //首先對x進行排序
    for(auto i : p){                   //依序走訪，如果遇到外積<0則不在凸包上
        while(hull.size()>=2 && check(i,hull[hull.size()-1],hull[hull.size()-2])){
            hull.pop_back();
        }
        hull.push_back(i);             //在凸包hull的每一點都符合外積小於0
    }
    int down_hull = hull.size();
    h = down_hull-1;
    hull.pop_back();                   //x最大的點會在凸包上，不用做兩次先pop一次
    reverse(p.begin(),p.end());        //將所有點逆序之後做一次上面的凸包
    for(auto i: p){
        while(hull.size() > down_hull && check(i,hull[hull.size()-1],hull[hull.size()-2])){
            hull.pop_back();
        }
        hull.push_back(i);
    }
    hull.pop_back();
}

void solve(){
    int d,sz = hull.size();
    rep(i,0,sz-1){
        d = i+1;
        rep(j,i+1,sz-1){
            while(check2(hull[i],hull[(j)%sz],hull[d],hull[(d+1)%sz]))
                d = (d+1)%sz;
            ans = max(ans,area((hull[d]-hull[i]),(hull[d]-hull[j])));
        }
    }
}

signed main(){
    Orz;
    cin>>n;
    p.assign(n,{0,0});
    rep(i,0,n-1)cin>>p[i].x>>p[i].y;
    convex_hull();
    ans = 0;
    solve();
    cout<<fixed<<setprecision(6);
    cout<<ans<<endl;
}