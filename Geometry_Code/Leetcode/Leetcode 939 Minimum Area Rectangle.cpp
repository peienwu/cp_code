class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        vector<vector<int>>p = points;
        int n = points.size();
        set<pair<int,int>>s;
        for(int i=0;i<n;i++)s.insert({p[i][0],p[i][1]});
        int ans = INT_MAX;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(s.find({p[i][0],p[j][1]})!=s.end() 
                   && s.find({p[j][0],p[i][1]})!=s.end()){
                    if(p[i][0] == p[j][0] || p[i][1] == p[j][1])continue;
                    ans = min(ans,abs(p[i][0]-p[j][0])*abs(p[i][1]-p[j][1]));
                }
            }
        }
        if(ans == INT_MAX)return 0;
        else return ans;
    }
};