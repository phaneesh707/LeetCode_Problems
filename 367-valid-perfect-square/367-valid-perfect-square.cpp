class Solution {
public:
    bool isPerfectSquare(int n) {
        if(n==1)
            return 1;
        long long l = 1,h = n;
        while(h-l>1){
            long long mid  = (l+h)/2;
            if(mid*mid > n)
                h = mid-1;
            else
                l = mid;
        }
        
        if(h*h == n || l*l== n)
            return true;
        return false;
        
    }
};