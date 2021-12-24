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
vector<int> cnt;
int n,ans = 0;

bool cmp(pt a, pt b){
    bool f1 = a < pt{0,0};
    bool f2 = b < pt{0,0};
    if(f1 != f2)return f1 < f2;
    return (a ^ b) > 0;
    //逆時針將點進行極角排序，從270度開始逆時針
}

//用cnt[i]統計區間長度為i的線段數量
void solve(pt id){
    vector<pt> pp;
    for(auto i : p){                         //以id為原點
        pt cur = i-id;
        if(cur == pt{0,0})continue;
        if(cur.y < 0){cur.x = -cur.x;cur.y = -cur.y;}
        if(cur.x < 0 && cur.y==0){cur.x = -cur.x;}
        pp.push_back(cur);
    }
    sort(all(pp),cmp);                      //將id當作原點進行排序
    int p1 = 0,p2 = 0,len = pp.size();      //雙指針找共線區間
    while(p1 < n-1){                        //最大化區間
        while(p2+1 < len && (pp[p1]^pp[p2+1]) == 0)p2++;
        cnt[p2-p1+2]+=1;
        p1 = p2+1;
    }
}

signed main(){
    Orz;
    cin>>n;
    p.assign(n,{0,0});
    cnt.resize(n+1,0);
    rep(i,0,n-1)cin>>p[i].x>>p[i].y;
    rep(i,0,n-1)solve(p[i]);
    int ans = (n*(n-1)*(n-2))/6;
    rep(i,3,n)ans-=(cnt[i]*(i-1)*(i-2))/6;
    cout<<ans<<endl;
}