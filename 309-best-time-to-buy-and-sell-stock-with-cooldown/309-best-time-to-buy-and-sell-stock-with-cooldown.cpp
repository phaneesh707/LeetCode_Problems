class Solution {
public:
    
    int recur(vector<int> a,int idx,int buy){
        if(idx >= size(a))
            return 0;
        
        int bought = 0,sold = 0,move = 0;
        if(buy == 1)
            bought = -a[idx] + recur(a,idx+1,0);
        else if(buy == 0)
            sold = a[idx] + recur(a,idx+2,1);
        
        move = recur(a,idx+1,buy);
        return max({bought,sold,move});
    }
    
    
    int memo(vector<int> a,int idx,int buy,vector<vector<int>> dp){
        if(idx >= size(a))
            return 0;
        if(dp[idx][buy]!=-1)
            return 0;
        
        int bought = 0,sold = 0,move = 0;
        if(buy == 1)
            bought = -a[idx] + memo(a,idx+1,0,dp);
        else if(buy == 0)
            sold = a[idx] + memo(a,idx+2,1,dp);
        
        move = memo(a,idx+1,buy,dp);
        return dp[idx][buy] = max({bought,sold,move});
    }
    
    int tabu(vector<int> a){
        int n = a.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy = 0;buy<2;buy++){
                int bought = 0,sold = 0,move = 0;
                if(buy == 1)
                    bought = -a[idx] + dp[idx+1][0];
                else{
                    if(idx+2>n)
                        sold = a[idx];
                    else
                        sold = a[idx] + dp[idx+2][1];
                }
                    

                move = dp[idx+1][buy];
                dp[idx][buy] = max({bought,sold,move});
            }
        }
        return dp[0][1];
    }

    
    
    int maxProfit(vector<int>& prices) {
        int n = size(prices);
        vector<vector<int>> dp(n,vector<int>(2,-1));
        // return recur(prices,0,1);
        // return memo(prices,0,1,dp);
        return tabu(prices);
    }
};