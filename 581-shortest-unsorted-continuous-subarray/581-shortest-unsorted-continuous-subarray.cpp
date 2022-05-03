class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> dummy = nums;
        sort(dummy.begin(),dummy.end());
        int i=0,j = nums.size()-1;
        while(i<nums.size() && dummy[i]==nums[i])
            i++;    
        while(j>=0 && dummy[j]==nums[j])
            j--;   
        if(i>=j)
            return 0;
        return j-i+1;
        
    }
};