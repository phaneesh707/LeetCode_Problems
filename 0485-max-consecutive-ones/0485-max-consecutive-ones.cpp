class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0,maxi = 0;
        for(auto it:nums){
            if(it == 1){
                count++;
                maxi = max(count,maxi);
            }else{
                count = 0;
            }
        }
        return maxi;
    }
};