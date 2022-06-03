class Solution {
public:
    
    //Time - O(N)   space - O(N)
    
    //calculates the max sum of non adj elements 
    int robbing(vector<int> nums){
        int n = nums.size(),maxi;
        vector<int> a(n,0);
        a[0] = nums[0];
        a[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            a[i] = max(nums[i]+a[i-2],a[i-1]);
        }
        
        return a[n-1];
    }
    
    //max amt can be found in either 0 to n-2 house or 1 to n-1 houses
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);
        if(n==3)
            return max(max(nums[0],nums[1]),nums[2]);
        
        int ele = nums[nums.size()-1];
        nums.pop_back();
        int r1 = robbing(nums);
        nums.push_back(ele);
        nums.erase(nums.begin());
        int r2 =robbing(nums);
        return max(r1,r2);
    }
};