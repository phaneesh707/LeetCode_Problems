class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = size(nums);
        for(int i=0;i<n-2;i++){
            int j = i+1,k=n-1;
            while(j<k){
                if(nums[j]+nums[k] == (-nums[i])){
                    res.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(nums[j]+nums[k] > (-nums[i])){
                    k--;
                }else
                    j++;
            }
        }
        vector<vector<int>> res1;
        for(auto it:res)
            res1.push_back(it);
        return res1;
    }
};