class Solution {
public:
    
    int rob(vector<int>& nums) {
//         Time - O(N) space - O(N)   N-size of nums
        // if(nums.size()==1)
        //     return nums[0];
        // if(nums.size()==2)
        //     return max(nums[0],nums[1]);
        // vector<int> a(nums.size(),0);
        // a[0]=nums[0];
        // a[1]=max(nums[0],nums[1]);
        // for(int i=2;i<nums.size();i++)
        //     a[i] = max(a[i-2]+nums[i],a[i-1]);
        
        
        
        
        //Time O(N)  space O(1)
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        int pres;
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            pres = max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=pres;
        }
        
        return pres;
    }      
};