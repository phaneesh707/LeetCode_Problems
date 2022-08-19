class Solution {
public:
    
    int recur(vector<int> a,int idx,int buy,int k){
        if(idx==size(a))
            return 0;
        if(k==0)
            return 0;
        
        int bought = 0,sold = 0,move = 0;
        if(buy == 1)
            bought = -a[idx] + recur(a,idx+1,0,k);
        else
            sold = a[idx] + recur(a,idx+1,1,k-1);
        move = recur(a,idx+1,buy,k);
        return max({bought,sold,move});
        
    }
    
    
    int memo(vector<int> a,int idx,int buy,int k,vector<vector<vector<int>>> dp){
        if(idx==size(a))
            return 0;
        if(k==0)
            return 0;
        
        if(dp[idx][buy][k]!=-1)
            return dp[idx][buy][k];
        
        int bought = 0,sold = 0,move = 0;
        if(buy == 1)
            bought = -a[idx] + memo(a,idx+1,0,k,dp);
        else
            sold = a[idx] + memo(a,idx+1,1,k-1,dp);
        move = memo(a,idx+1,buy,k,dp);
        return max({bought,sold,move});
        
    }
    
    
    int tabu(vector<int> a,int j){
        vector<vector<vector<int>>> dp(size(a)+1,vector<vector<int>>(2,vector<int>(j+1,0)));
        
        for(int idx=size(a)-1;idx>=0;idx--){
            for(int buy = 0;buy<2;buy++){
                for(int k = j;k>0;k--){
                    int bought = 0,sold = 0,move = 0;
                    if(buy == 1)
                        bought = -a[idx] + dp[idx+1][0][k];
                    else
                        sold = a[idx] +dp[idx+1][1][k-1];
                    move = dp[idx+1][buy][k];
                    dp[idx][buy][k] = max({bought,sold,move});
                }
            }
        }
        return dp[0][1][j];
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<vector<int>>> dp(size(prices),vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return recur(prices,0,1,k);
        // return memo(prices,0,1,k,dp);
        return tabu(prices,k);
        
    }
};