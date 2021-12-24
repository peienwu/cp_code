#define eps 1e-8
#define ld long double
#define pdd pair<ld,ld>
#define x first
#define y second

class Solution {
public:
    pdd p[105];int n;
    
    ld dis_all(pdd mid){
        ld sum;
        for(int i = 0;i < n;i++){
            ld x = p[i].x - mid.x,y = p[i].y - mid.y;
            sum += sqrt(x * x + y * y);
        }
        return sum;
    }
    
    double getMinDistSum(vector<vector<int>>& pos) {
        srand(time(NULL));
        n = pos.size();
        for(int i = 0;i < n;i++)p[i] = {pos[i][0],pos[i][1]};
        pdd cur = p[0];ld mid_dis = dis_all(p[0]);
        ld test_size = 150.0;
        while(test_size > eps){
            pdd newp = cur;
            int temp = rand();
            newp.x += cos(temp) * test_size;
            newp.y += sin(temp) * test_size;
            ld new_dis = dis_all(newp);
            if(new_dis < mid_dis){
                mid_dis = new_dis;
                cur = newp;
            }
            else test_size *= 0.99;
        }
        return mid_dis;
    }
};