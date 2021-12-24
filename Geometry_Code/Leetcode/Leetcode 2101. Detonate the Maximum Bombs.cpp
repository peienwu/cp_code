#define pii pair<int,int>
#define ld long double

class Solution {
public:
    
    vector<int> E[105];
    ld dis(pii a,pii b){
        int x = a.first - b.first,y = a.second - b.second;
        return sqrt((long long)x * x + (long long)y * y);
    }
    int sum = 1;
    bool vis[105];
    void dfs(int now){
        vis[now] = 1;
        for(auto i : E[now]){
            if(vis[i])continue;
            sum++;vis[i] = 1;
            dfs(i);
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bomb) {
        int n = bomb.size(),ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                pii a = {bomb[i][0],bomb[i][1]},b = {bomb[j][0],bomb[j][1]};
                int r1 = bomb[i][2],r2 = bomb[j][2];
                ld d = dis(a,b);
                if(r1 >= d)E[i].push_back(j);
                if(r2 >= d)E[j].push_back(i);
            }
        }
        for(int i = 0;i < n;i++){
            fill(vis,vis+105,0);
            sum = 1;
            dfs(i);
            ans = max(ans,sum);
        }
        return ans;
    }
};