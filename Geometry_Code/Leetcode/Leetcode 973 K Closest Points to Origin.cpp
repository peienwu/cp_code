class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        multimap<int,int> mp;
        for(int i = 0;i < n;i++){
            int x = points[i][0];
            int y = points[i][1];
            mp.insert({x * x + y * y,i});
        }
        auto it = mp.begin();
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            int id = it->second;
            ans.push_back(points[id]);
            it++;
        }
        return ans;
    }
};