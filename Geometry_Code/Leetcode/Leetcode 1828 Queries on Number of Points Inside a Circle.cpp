class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size(),m = points.size();
        vector<int> ans;ans.resize(n);
        for(int i = 0;i < n;i++){
            int rx = queries[i][0],ry = queries[i][1],sum = 0;
            for(int j = 0;j < m;j++){
                int x = points[j][0] - rx,y = points[j][1] - ry;
                if(x * x + y * y <= queries[i][2] * queries[i][2])sum++;
            }
            ans[i] = sum;
        }
        return ans;
    }
};