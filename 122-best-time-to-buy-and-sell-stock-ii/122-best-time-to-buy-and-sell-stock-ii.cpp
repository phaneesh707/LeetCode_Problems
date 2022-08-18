class Solution {
public:
    //buy=1 indicates can buy 
    int recur(vector<int> a,int idx,int buy,int n){
        if(idx == n-1){
            if(buy == 0)
                return a[n-1];
            return 0;
        }
        int bought = 0,sold = 0, move = 0;
        if(buy==1)
            bought = -a[idx] + recur(a,idx+1,0,n);
        else
            sold = a[idx] + recur(a,idx+1,1,n);
        move = recur(a,idx+1,buy,n);
        return max({bought,sold,move});
    }
    
    
    int memo(vector<int> a,int idx,int buy,int n,vector<vector<int>> dp){
        if(idx == n-1){
            if(buy == 0)
                return a[n-1];
            return 0;
        }
        
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        
        int bought = 0,sold = 0, move = 0;
        if(buy==1)
            bought = -a[idx] + memo(a,idx+1,0,n,dp);
        else
            sold = a[idx] + memo(a,idx+1,1,n,dp);
        move = memo(a,idx+1,buy,n,dp);
        return dp[idx][buy] =  max({bought,sold,move});
    }
    
    
    int tabu(vector<int> a,int n){
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[n-1][0] = a[n-1];
        
        for(int idx=n-2;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                int bought = 0,sold = 0, move = 0;
                if(buy==1)
                    bought = -a[idx] + dp[idx+1][0];
                else
                    sold = a[idx] + dp[idx+1][1];
                move = dp[idx+1][buy];
                dp[idx][buy] = max({bought,sold,move});
            }
        }
        return dp[0][1];
    }
    
    
    int spaceOpti(vector<int> a,int n){
        vector<int> prev(2);
        vector<int> pres(2);
        prev[0] = a[n-1];
        prev[1] = 0;
        
        for(int idx=n-2;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                int bought = 0,sold = 0, move = 0;
                if(buy==1)
                    bought = -a[idx] + prev[0];
                else
                    sold = a[idx] + prev[1];
                move = prev[buy];
                pres[buy] = max({bought,sold,move});
            }
            prev = pres;
        }
        return prev[1];
    }
    
    int maxProfit(vector<int>& prices) {
        int n = size(prices);
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return recur(prices,0,1,n);
        // return memo(prices,0,1,n,dp);
        // return tabu(prices,n);
        return spaceOpti(prices,n);
    }
};