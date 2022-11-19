class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int votes = 0,n = size(nums),ele = INT_MAX;
        for(int i=0;i<n;i++){
            if(votes == 0) ele = nums[i];
            
            if(ele == nums[i]) votes++;
            else votes--;
        }
        return ele;
        
        
    }
};