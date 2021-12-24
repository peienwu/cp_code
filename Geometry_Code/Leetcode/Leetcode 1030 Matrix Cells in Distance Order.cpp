class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int n = rows,m = cols;
        multimap<int,pair<int,int>> mp;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                int dis = abs(i - rCenter) + abs(j - cCenter);
                mp.insert({dis,{i,j}});
            }
        }
        vector<vector<int>> ans;ans.resize(n*m);
        for(int i=0;i<n*m;i++)ans[i].resize(2,0);
        int id = 0;
        for(auto it : mp){
            ans[id][0] = (it.second.first);
            ans[id][1] = (it.second.second);
            id++;
        }
        return ans;
    }
};