//recursion / memoization
// class Solution {
// public:
    
//     int stairs(int n){
//         if(n<=1)
//             return 1;
//         int l = stairs(n-1);//doing all posible operations 
//         int r = stairs(n-2);
//         return l+r;//counting 
//     }
    
//     int climbStairs(int n) {
//         return stairs(n);        
        
//     }
// };


class Solution {
public:
    //Time - O(N) space - O(1)
    int climbStairs(int n) {
        
        int pres = 1,prev = 1,curr=1;
        for(int i=2;i<=n;i++){
            curr = pres+prev;
            prev = pres;
            pres = curr;
            
        }
        return curr;
        
    }
};