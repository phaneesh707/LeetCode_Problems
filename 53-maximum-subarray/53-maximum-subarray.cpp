class Solution {
public:
    
    
    
    int maxSubArray(vector<int>& nums) {
        int n = size(nums);
        int maxi = INT_MIN;
        //O(N^2) tle
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         maxi = max(sum,maxi);
        //     }
        // }
        
        maxi = INT_MIN;
        int max_end = 0;
        
        for(int i=0;i<n;i++){
            max_end += nums[i];
            if(maxi<max_end)
                maxi = max_end;
            if(max_end<0)
                max_end = 0;
        }
        
        return maxi;
    }
};