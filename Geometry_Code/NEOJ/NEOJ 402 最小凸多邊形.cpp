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
        if(x-b.x<=eps && y-b.y<=eps)return true;
        return false;
    }
    pt operator+(pt b) {return {x + b.x, y + b.y};} //向量相加
    pt operator-(pt b) {return {x - b.x, y - b.y};} //向量相減
    int operator^(pt b) {return x * b.y - y * b.x;} //向量外積cross
    int operator*(pt b) {return x * b.x + y * b.y;} //向量內積dot
};
bool cmp(pt a, pt b){
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}

vector<pt> p;

bool check(pt a,pt b,pt o){
    int cross = (a - o)^(b - o);
    return cross >= 0;
}

int n,t;

vector<pt> convex_hull(){
    vector<pt> hull;
    sort(p.begin(),p.end(),cmp);       //首先對x進行排序
    for(auto i : p){                   //依序走訪，如果遇到外積<0則不在凸包上
        while(hull.size() > 1 && check(i,hull[hull.size()-1],hull[hull.size()-2])){
            hull.pop_back();
        }
        hull.push_back(i);             //在凸包hull的每一點都符合外積小於0
    }
    int down_hull = hull.size();
    hull.pop_back();                   //x最大的點會在凸包上，不用做兩次先pop一次
    reverse(p.begin(),p.end());        //將所有點逆序之後做一次上面的凸包
    for(auto i: p){
        while(hull.size() > down_hull && check(i,hull[hull.size()-1],hull[hull.size()-2])){
            hull.pop_back();
        }
        hull.push_back(i);
    }
    return hull;                       //起點會經過兩次，剛好來算有向面積
}

signed main(){
    Orz;
    cin>>t;
    while(t--){
        cin>>n;
        p.assign(n,{0,0});
        rep(i,0,n-1)cin>>p[i].x>>p[i].y;
        vector<pt> hull = convex_hull();
        int area = 0,len = hull.size();
        for(int i=0;i<len-1;i++)area += (hull[i]^hull[i+1]);
        cout<<fixed<<setprecision(1)<<((ld)area/2)<<endl;
    }
}