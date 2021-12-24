class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<vector<int>> p = coordinates;
        int n = p.size();
        for(int i = 0;i < n-2;i++){
            int x1 = p[i+1][0] - p[i][0],y1 = p[i+1][1] - p[i][1];
            int x2 = p[i+2][0] - p[i+1][0],y2 = p[i+2][1] - p[i+1][1];
            if(x1 * y2 != x2 * y1)return false;
        }
        return true;
    }
};
