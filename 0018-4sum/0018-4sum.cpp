class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = size(nums);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long sum = 1LL*target-1LL*nums[i]-1LL*nums[j];
                int  a = j+1,b=n-1;
                
                while(a<b){
                    if(sum == nums[a]+nums[b]){
                        res.push_back({nums[i],nums[j],nums[a],nums[b]});
                        while(a<b && nums[a]==res.back()[2]) a++;
                        while(a<b && nums[b]==res.back()[3]) b--;
                    }else if(sum>nums[a]+nums[b])
                        a++;
                    else
                        b--;
                        
                    
                }
                while(j+1<n && nums[j+1] == nums[j]) j++;
            }
            while(i+1<n && nums[i+1] == nums[i]) i++;
        }
        return res;
    } 
};