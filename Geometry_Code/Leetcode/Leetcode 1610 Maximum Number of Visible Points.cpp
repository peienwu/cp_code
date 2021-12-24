#define ld long double
const int N = 1e5+5;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& loc) {
        vector<ld> ang;
        int overlap = 0,n = points.size(),ans = 0;
        for(auto p : points){
            if(p[0] == loc[0] && p[1] == loc[1])overlap++;
            else ang.push_back(atan2l(p[1]-loc[1],p[0]-loc[0]) * 180 / (ld)M_PI);
        }
        int sz = ang.size();
        for(int i = 0;i < sz;i++)ang.push_back(ang[i] + 360);
        sort(ang.begin(),ang.end());
        sz = ang.size();
        for(int i = 0,it2 = 0;i < sz;i++){
            while(it2 < sz && ang[it2] - ang[i] <= angle)it2++;
            ans = max(ans,it2 - i);
        }
        return ans + overlap;
    }
};