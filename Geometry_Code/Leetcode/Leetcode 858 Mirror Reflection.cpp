class Solution {
public:
    int gcd(int a,int b){
        if(a == 0)return b;
        return gcd(b % a,a);
    }
    
    int mirrorReflection(int p, int q) {
        int len = p * q / gcd(q,p);
        int a = (len / p) % 2,b = (len / q) % 2;
        if(a == 0 && b == 1)return 0;
        else if(a == 1 && b == 1)return 1;
        else return 2;
        
    }
};