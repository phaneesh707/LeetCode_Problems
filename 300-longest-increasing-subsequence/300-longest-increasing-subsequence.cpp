class Solution {
public:
    //doesn't handle negative val when converted to tabu
    int recur(vector<int> a,int idx,int prev){
        if(size(a) == idx)
            return 0;
        
        
        int take = 0,notTake = 0,move = 0;
        if(a[idx]>prev)
            take = 1 + recur(a,idx+1,a[idx]);
        else
            notTake = recur(a,idx+1,prev);
        move = recur(a,idx+1,prev);
        return max({take,notTake,move});
    }
    
    int recur1(vector<int> a,int idx,int prev){
        if(idx == size(a))
            return 0;
        
       
        int take = 0,notTake = 0;
        notTake = recur1(a,idx+1,prev);
        
        if(prev==-1 || a[idx]>a[prev])
            take = 1 + recur1(a,idx+1,idx);
        
            
        return max(take,notTake);
    }
    
    
    int memo(vector<int> a,int idx,int prev,vector<vector<int>>& dp){
        if(idx == size(a))
            return 0;

        if(dp[idx][prev+1]!=-1)
            return dp[idx][prev+1];
        
        int take = 0,notTake = 0;
        notTake = memo(a,idx+1,prev,dp);
        if(prev == -1 || a[idx]>a[prev])
            take = 1 + memo(a,idx+1,idx,dp);
            
        return dp[idx][prev+1] =  max(take,notTake);
    }
    
    
    int tabu(vector<int> a){
        int n = size(a);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        
        for(int idx = n-1;idx>=0;idx--){
            for(int prev = n-1;prev>=-1;prev--){
                int take = 0,notTake = 0;
                notTake = dp[idx+1][prev+1];
                if(prev == -1 || a[idx]>a[prev])
                    take = 1 +dp[idx+1][idx+1];
                
                dp[idx][prev+1] =  max(take,notTake);   
            }
        }
        return dp[0][0];
    }
    
    int spaceOpti(vector<int> a){
        int n = size(a);
        vector<int> ahead(n+1,0);
        vector<int> pres(n+1,0);
        
        
        
        for(int idx = n-1;idx>=0;idx--){
            for(int prev = n-1;prev>=-1;prev--){
                int take = 0,notTake = 0;
                notTake = ahead[prev+1];
                if(prev == -1 || a[idx]>a[prev])
                    take = 1 +ahead[idx+1];
                
                pres[prev+1] =  max(take,notTake);   
            }
            ahead = pres;
        }
        return ahead[0];
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        // int n = size(nums);
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return recur1(nums,0,-1);
        // return memo(nums,0,-1,dp);
        // return tabu(nums);
        return spaceOpti(nums);
    }
};