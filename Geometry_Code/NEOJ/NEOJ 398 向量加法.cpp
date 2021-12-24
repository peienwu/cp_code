#include <bits/stdc++.h>
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define int long long
#define double long double
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define rep2(i,l,r) for(int i=l;i<r;i++)
#define pii pair<int,int>
#define x first
#define y second
#define eps (1e-9)
#define INF 1e10
#define N 2001
#define ll long long
#define ld long double
#define int long long
using namespace std;
int n;

signed main(){
    cin>>n;
    vector<int> vec(n);
    rep2(i,0,n){
        string s;cin>>s;
        int num = 0,times = 1000000000;
        for(int i=2;i<=10;i++){
            num += (s[i]-'0')*times;
            times/=10;
        }
        vec[i] = num;
    }
    unordered_multimap<int,int> mp;
    for(int i=0;i<n;i++){
        mp.insert({vec[i],i});
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans += mp.count(vec[i] + vec[j]);
        }
    }
    cout<<ans<<endl;
}