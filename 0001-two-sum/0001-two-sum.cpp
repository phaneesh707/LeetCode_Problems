class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res(2);
        int n = size(nums);
        for(int i=0;i<n;i++){
            if(m.find(target-nums[i])!=m.end() && m[target-nums[i]]!=i){
                res[0] = i;
                res[1] = m[target-nums[i]];
                break;
            }else
                m[nums[i]] = i;
        }
        return res;
    }
};