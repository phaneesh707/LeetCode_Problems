class Solution {
public:
    int rob(vector<int>& nums) {
        int maxi = 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        vector<int> a(nums.size(),0);
        a[0]=nums[0];
        a[1]=nums[1];
        for(int i=2;i<nums.size();i++){
            a[i] = nums[i]+*max_element(a.begin(),a.begin()+i-1);
        }
        
        return *max_element(a.begin(),a.end());
    }
};