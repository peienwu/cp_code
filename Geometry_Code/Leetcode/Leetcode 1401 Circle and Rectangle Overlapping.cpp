class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int x = clamp(x_center,x1,x2) - x_center;
        int y = clamp(y_center,y1,y2) - y_center;
        return x*x + y*y <= radius * radius;
    }
};
