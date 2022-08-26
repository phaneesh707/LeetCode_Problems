class Solution {
public:
    
    
    vector<int> LIS(vector<int> a){
        int n = size(a),maxi = 1,maxi_i=0;
        vector<int> dp(n,1),hash(n,0);
        for(int i=0;i<n;i++)
            hash[i] = i;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(a[i]%a[j]==0 && dp[i]<1+dp[j] ){
                    dp[i] = dp[j]+1;
                    hash[i] = j;   
                }
            }
            
            if(maxi<dp[i]){
                maxi = dp[i];
                maxi_i = i;
            }
           
        }
        
        vector<int> res;
        while(maxi--){
            res.push_back(a[maxi_i]);
            maxi_i = hash[maxi_i];
        }
        
        reverse(res.begin(),res.end());
        return res;
        
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return LIS(nums);
    }
};