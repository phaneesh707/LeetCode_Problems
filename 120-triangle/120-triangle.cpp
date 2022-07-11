class Solution {
public:
    
    int recur(vector<vector<int>> a,int i,int j){
        if(i==a.size()-1)
            return a[i][j];
    
        int down = a[i][j] + recur(a,i+1,j);
        int diag = a[i][j] + recur(a,i+1,j+1);
        return min(down,diag);
    }
    
    int memo(vector<vector<int>> a,int i,int j,vector<vector<int>> dp){
        if(i==a.size()-1)
            return a[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down = a[i][j] + recur(a,i+1,j);
        int diag = a[i][j] + recur(a,i+1,j+1);
        return dp[i][j] = min(down,diag);
    }
    
    int tabu(vector<vector<int>> a){
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
            dp[n-1][i] = a[n-1][i];
        
        //tabu always reverse of recur
        for(int i=n-2;i>=0;i--){
            for(int j = i;j>=0;j--){
                dp[i][j] = a[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
            
    }
    
    
    int spaceOpt(vector<vector<int>> a){
        int n = a.size();
        vector<int> prev(n,-1);
        vector<int> curr(n,-1);
        for(int i=0;i<n;i++)
            prev[i] = a[n-1][i];
        
        for(int i=n-2;i>=0;i--){
            for(int j = i;j>=0;j--)
                curr[j] = a[i][j] + min(prev[j],prev[j+1]);
            
            prev = curr;
            
        }
        
        return prev[0];
            
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        // return recur(t,0,0);
        
        // vector<vector<int>> dp(t.size(),vector<int>(t.size(),-1));
        // return memo(t,0,0,dp);
        
        // return tabu(t);
        
        return spaceOpt(t);
        
    }
};