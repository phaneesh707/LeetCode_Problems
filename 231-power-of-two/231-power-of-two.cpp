class Solution {
public:
   
    
    bool isPowerOfTwo(int n) {
        if(n<1)
            return false;
        int count = 0;
        n = abs(n);
            while(n){
                count+=(n&1);
                n=n>>1;
                if(count>1)
                    return false;
            }
        return true;
    }
};