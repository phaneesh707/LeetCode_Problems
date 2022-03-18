class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> a;
        int s=nums.size();
        for(int i=0;i<s;i++){
            a.insert(nums[i]);
        }
        if(a.size()==nums.size()) return false;
        else return true;
        
    }
};