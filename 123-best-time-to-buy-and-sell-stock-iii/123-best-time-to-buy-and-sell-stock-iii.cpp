class Solution {
public:
    
    int recur(vector<int> a,int idx,int buy,int count){
        
        if(idx == size(a) || count ==0)
            return 0;
        
        int bought = 0,sold = 0, move = 0;
        if(buy==1)
            bought = -a[idx] + recur(a,idx+1,0,count);
        else
            sold = a[idx] + recur(a,idx+1,1,count-1);
        move = recur(a,idx+1,buy,count);
        return max({bought,sold,move});
    }
    
    
    int memo(vector<int> a,int idx,int buy,int count,vector<vector<vector<int>>>& dp){
        
        if(idx == size(a) || count ==0)
            return 0;
        if(dp[idx][buy][count]!=-1)
            return dp[idx][buy][count];
        
        int bought = 0,sold = 0, move = 0;
        if(buy==1)
            bought = -a[idx] + memo(a,idx+1,0,count,dp);
        else
            sold = a[idx] + memo(a,idx+1,1,count-1,dp);
        move = memo(a,idx+1,buy,count,dp);
        return dp[idx][buy][count] = max({bought,sold,move});
    }
    
    
    int tabu(vector<int> a){
        int n = size(a);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,0)));
        dp[n-1][0][1]=a[n-1];
        dp[n-1][0][2]=a[n-1];
            
        for(int idx=n-2;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                for(int count = 2;count>0;count--){
                    int bought = 0,sold = 0, move = 0;
                    if(buy==1)
                        bought = -a[idx] + dp[idx+1][0][count];
                    else
                        sold = a[idx] +dp[idx+1][1][count-1];
                    move = dp[idx+1][buy][count];
                    dp[idx][buy][count] = max({bought,sold,move});
                }
                
            }
        }
        return dp[0][1][2];
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = size(prices);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        // return recur(prices,0,1,2);
        // return memo(prices,0,1,2,dp);
        return tabu(prices);

    }
};