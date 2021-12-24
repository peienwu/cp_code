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
    int x,y,ind;
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
    int dis() {return x*x + y*y;}
};

vector<pt> p,hull;
pt pt_ans;
int n,h;

bool check(pt a, pt b, pt o){
    pt aa = a - o;
    pt bb = b - o;
    return (aa ^ bb) >= 0;
}

bool check2(pt a,pt b,pt c,pt d){
    int aa = abs((a - c)^(b - c));
    int bb = abs((a - d)^(b - d));
    return aa < bb;
}

bool cmp(pt a, pt b){
    if(a == b)return a.ind < b.ind;
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}

void convex_hull(){
    stable_sort(all(p),cmp);
    rep(i,0,n-2)if(p[i] == p[i+1])p[i+1].ind = p[i].ind;
    hull.clear();
    for(auto i : p){
        while(hull.size() > 1 && check(i,hull[hull.size()-1],hull[hull.size()-2]))
            hull.pop_back();
        hull.push_back(i);
    }
    int sz = hull.size();
    h = hull.size()-1;
    hull.pop_back();
    reverse(all(p));
    for(auto i : p){
        while(hull.size() > sz && check(i,hull[hull.size()-1],hull[hull.size()-2]))
            hull.pop_back();
        hull.push_back(i);
    }
    hull.pop_back();
}

void solve(){
    int ans = 0,d = h,sz = hull.size();
    rep(i,0,sz-1){
        while(check2(hull[i],hull[(i+1)%sz],hull[d],hull[(d+1)%sz]))
            d = (d+1)%sz;
        if(ans < (hull[i]-hull[d]).dis()){
            ans = (hull[i]-hull[d]).dis();
            int a = hull[i].ind,b = hull[d].ind;if(a > b)swap(a,b);
            pt_ans = {a,b};
        }
        else if(ans == (hull[i]-hull[d]).dis()){
            int a = hull[i].ind,b = hull[d].ind;if(a > b)swap(a,b);
            if(pt_ans > (pt){a,b})pt_ans = {a,b};
        }
        if(ans < (hull[(i+1)%sz]-hull[d]).dis()){
            ans = (hull[(i+1)%sz]-hull[d]).dis();
            int a = hull[(i+1)%sz].ind,b = hull[d].ind;if(a > b)swap(a,b);
            pt_ans = {a,b};
        }
        else if(ans == (hull[(i+1)%sz]-hull[d]).dis()){
            int a = hull[(i+1)%sz].ind,b = hull[d].ind;if(a > b)swap(a,b);
            if(pt_ans > (pt){a,b})pt_ans = {a,b};
        }
    }
}

signed main(){
    Orz;
    while(cin>>n){
        if(n == 0)break;
        pt_ans = (pt){0,0};
        p.resize(n,{0,0});
        rep(i,0,n-1){
            cin>>p[i].x>>p[i].y;
            p[i].ind = i;
        }
        convex_hull();
        solve();
        cout<<pt_ans.x<<" "<<pt_ans.y<<endl;
    }
}

/*
5
9 1
1 5
1 2
9 9
5 1
 */