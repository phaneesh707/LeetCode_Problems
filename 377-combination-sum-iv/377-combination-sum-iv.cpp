class Solution {
public:
    
    int recur(vector<int> a,int k,int idx){
        if(k == 0)
            return 1;
        if(idx ==  0){
            if(k%a[0]==0)
                return 1;
            return 0;
        }
        
        int notTake = recur(a,k,idx-1);
        int take = 0;
        if(a[idx]<=k)
            take = 1 +  recur(a,k-a[idx],idx);
        return take + notTake;
        
    }
    
    int memo(vector<int> a,int k,int idx,vector<vector<int>> dp){
        if(k == 0)
            return 1;
        if(idx ==  0){
            if(k%a[0]==0)
                return 1;
            return 0;
        }
        
        int notTake = memo(a,k,idx-1,dp);
        int take = 0;
        if(a[idx]<=k)
            take = 1 +  memo(a,k-a[idx],idx,dp);
        return dp[idx][k] =  take + notTake;
        
    }
    
    int tabu(vector<int> a,int k){
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        for(int i=0;i<n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=k;i++){
            if(i%a[0]==0)
                dp[0][i] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(a[i]<=j)
                    take = dp[i][j-a[i]];
                dp[i][j] = take + notTake;
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[n-1][k];
    }
    
    int spaceOpti(vector<int> a,int k){
        int n = a.size();
        vector<int> pres(k+1,0),prev(k+1,0);
        prev[0] = pres[0] = 1;
        for(int i=1;i<=k;i++){
            if(i%a[0]==0)
                prev[i] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                int notTake = prev[j];
                int take = 0;
                if(a[i]<=j)
                    take = 1 +  pres[j-a[i]];
                pres[j] = take + notTake;
            }
            prev = pres;
        }
        return prev[k];
    }
    
    
    
    int coinChange(vector<int> nums, int target) {
        vector<uint> dp(target + 1); dp[0] = 1;
        for (int curTarget = 1; curTarget <= target; curTarget++) 
            for (auto& num : nums) 
                if (num <= curTarget) 
                    dp[curTarget] += dp[curTarget - num];   
        return dp[target];
    }

    
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(target+1,-1));
        // return recur(nums,target,n-1);
        // return memo(nums,target,n-1,dp);
        // return tabu(nums,target);
        // return spaceOpti(nums,target);
        return coinChange(nums,target);
    }
};