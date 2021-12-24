class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size(),ans = 0;
        for(int i = 0;i < n;i++){
            int maxR = 0,maxC = 0;
            for(int j = 0;j < n;j++){
                if(grid[i][j] > 0)ans++;        //由上往下看
                maxR = max(maxR,grid[i][j]);    //由側邊看
                maxC = max(maxC,grid[j][i]);    //由前面看
            }
            ans += maxR + maxC;
        }
        return ans;
    }
};