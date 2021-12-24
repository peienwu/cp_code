class Solution {
public:
    
    int gcd(int a,int b){
        if(a > b)swap(a,b);
        if(a == 0)return b;
        return gcd(b % a, a);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(),ans = 0;
        for(int i = 0;i < n;i++){
            map<pair<int,int>,int> mp;
            int same = 0,hori = 0;
            for(int j = i+1;j < n;j++){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if(dx == 0 && dy == 0){same++;continue;}
                if(dx == 0 && dy != 0){hori++;continue;}
                int g = gcd(abs(dx),abs(dy));
                if(dy < 0 || (dy == 0 && dx < 0)){dx = -dx;dy = -dy;}
                mp[{dx/g,dy/g}]++;
            }
            int sum = hori + same + 1;
            for(auto it : mp)sum = max(sum,it.second + 1);
            ans = max(ans,sum);
        }
        return ans;
    }
};