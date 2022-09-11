class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=nums[0],n=size(nums);
        for(int i=1;i<n;i++)
            x^=nums[i];
        return x;
        
    }
};