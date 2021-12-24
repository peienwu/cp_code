class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(),ans = 0;
        vector<vector<int>> p = points;
        for(int i = 0;i < n-1;i++){
            ans += max(abs(p[i+1][0] - p[i][0]),abs(p[i+1][1] - p[i][1]));
        }
        return ans;
    }
};