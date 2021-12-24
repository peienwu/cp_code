#include <bits/stdc++.h>
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define rep(i,a,b) for(int i=a;i<=b;i++)
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
vector<pt> point;
int dir(pt a, pt b, pt o) {                         //方向函數
    int cross = (a - o) ^ (b - o);
    if(fabs(cross) <= eps) return 0;
    else if(cross > 0) return 1;
    else return -1;
}
bool onseg(pt a, pt b, pt o){                       //o是否在ab線段上
    int cross = (a - o) ^ (b - o);                  //是否平行
    int dot = (a - o) * (b - o);                    //是否在線段中
    return (cross == 0)&&(dot <= 0);
}

bool Intersection(pt a, pt b, pt c, pt d){          //線段ab是否與cd相交
    if(onseg(a,b,c)||onseg(a,b,d))return true;      //點c、d是否洽在線段ab上
    if(onseg(c,d,a)||onseg(c,d,b))return true;      //點a、b是否洽在線段cd上
    if(dir(a,b,c)*dir(a,b,d)==-1 && dir(c,d,a)*dir(c,d,b)==-1)
        return true;                                //對於線段兩端點看另外兩端點必須方向相反
    return false;
}
int n,t;

void solve(){
    point.assign(4,{0,0});
    rep(i,0,3)cin>>point[i].x>>point[i].y;
    if(Intersection(point[0],point[1],point[2],point[3])){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}

signed main(){
    Orz;
    int t;cin>>t;
    while(t--){
        solve();
    }
}
