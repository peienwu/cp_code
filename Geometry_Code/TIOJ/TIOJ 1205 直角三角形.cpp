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

vector<pt> p,temp,pp;
vector<int>  cnt;
int n,ans = 0;

bool cmp(pt a, pt b){
    bool f1 = a < pt{0,0};
    bool f2 = b < pt{0,0};
    if(f1 != f2)return f1 < f2;
    return (a ^ b) > 0;
    //逆時針將點進行極角排序，從270度開始逆時針
}

//O(n)枚舉每個點當直角情況
int solve(pt id){
    pp.clear();cnt.clear();temp.clear();
    for(pt i : p){
        pt cur = i - id;
        if(cur == pt{0,0})continue;
        temp.push_back(cur);
    }
    sort(all(temp),cmp);            //以id為原點進行極角排序
    pp.push_back(temp[0]);          //pp每一角度只存至多一個點
    cnt.push_back(1);               //考慮每個點共線情況
    int len = temp.size();
    rep(i,1,len-1){
        int cross = temp[i]^temp[i-1],dot = temp[i]*temp[i-1];
        if(cross == 0 && dot >= 0)cnt[cnt.size()-1] += 1;   //共線數量+=1
        else {pp.push_back(temp[i]);cnt.push_back(1);}      //非共線設定數量為1
    }
    len = pp.size();            //考慮橫跨一周的情況
    rep(i,0,len-1){             //雙指針i,p1可能會超過一圈
        pp.push_back(pp[i]);    //將點再繞一圈
        cnt.push_back(cnt[i]);
    }
    int ans = 0,p1 = 0;
    rep(i, 0, len-1){
        while(p1 < i+len && (pp[i]^pp[p1]) >= 0 && (pp[i]*pp[p1]) > 0)p1 += 1;
        //夾銳角的情況要p1+=1
        if((pp[i]^pp[p1]) > 0 && (pp[i]*pp[p1]) == 0)ans += cnt[i]*cnt[p1];
        //正向的直角三角形，若共線則兩者數量相乘
    }
    return ans;
}

signed main(){
    Orz;
    while(cin>>n){
        if(n == 0)break;
        p.assign(n,{0,0});
        rep(i,0,n-1)cin>>p[i].x>>p[i].y;
        
        int ans = 0;
        rep(i,0,n-1){
            ans += solve(p[i]);
        }
        cout<<ans<<endl;
    }
}