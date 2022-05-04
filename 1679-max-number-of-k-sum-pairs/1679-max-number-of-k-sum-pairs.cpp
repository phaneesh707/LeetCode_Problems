class Solution {
public:
    //time complexity - O(Nlog(N))
    //sort and 2 ptrs
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1,count=0;
        while(i<j){
            if(nums[i]+nums[j] ==  k){
                count++;
                i++;j--;
            }else if(nums[i]+nums[j] >  k)
                j--;
            else
                i++;
        }
        return count;
    }
};