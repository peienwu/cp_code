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
vector<pt> a;
int dir(pt a, pt b, pt o) {
    int cross = (a - o) ^ (b - o);
    if(fabs(cross) <= eps) return 0;
    else if(cross > 0) return 1;
    else return -1;
}

int n,t;

signed main(){
    Orz;
    cin>>n;
    a.resize(n+2);
    rep(i,1,n)cin>>a[i].x>>a[i].y;
    int right = 0,left = 0,turn = 0;
    pt pre = a[1],from = a[2];
    for(int i=3;i<=n;i++){
        int ori = dir(a[i],from,pre);
        if(ori == 1)right+=1;
        else if(ori == -1)left+=1;
        else if(ori == 0 && ((a[i]-from)*(from-pre))<0)turn+=1;
        pre = from;from = a[i];
    }
    cout<<left<<" "<<right<<" "<<turn<<endl;
}