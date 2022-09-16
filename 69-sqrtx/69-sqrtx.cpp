class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        
        long long l = 0,h = x;
        while(h-l>1){
            long long mid = (l+h)/2;
            if(mid*mid >x)
                h = mid-1;
            else
                l = mid;
        }
        
        if(h*h>x)
            return l;
        else return h;
        
    }
};