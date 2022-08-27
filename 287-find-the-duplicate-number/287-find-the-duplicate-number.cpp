class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = size(nums);
        for(int i=0;i<=n;i++){
            if(m.find(nums[i])!=m.end())
                return nums[i];
            else
                m[nums[i]] = 1;
        }
        return 0;
    }
};