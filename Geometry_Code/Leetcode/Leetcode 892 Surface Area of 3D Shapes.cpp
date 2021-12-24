class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0,n = grid.size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] > 0)ans += 4 * grid[i][j] + 2;
                if(i < n - 1){
                    ans -= min(grid[i][j],grid[i+1][j])*2;
                }
                if(j < n - 1){
                    ans -= min(grid[i][j],grid[i][j+1])*2;
                }
            }
        }
        return ans;
    }
};