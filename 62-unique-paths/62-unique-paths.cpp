class Solution {
public:
    int recur(int m,int n,int i,int j){
        if(i==0 && j==0){
            return 1;
        }
        int right=0,down=0;
        if(i-1>=0 && j>=0)
            right+= recur(m,n,i-1,j);
        if(j-1>=0 && i>=0)
            down+= recur(m,n,i,j-1);
        return right+down;
            
    }
    
    
    int memo(int m,int n,int i,int j,vector<vector<int>> dp){
        if(i==0 && j==0){
            return 1;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right=0,down=0;
        if(i-1>=0 && j>=0)
            right+= memo(m,n,i-1,j,dp);
        if(j-1>=0 && i>=0)
            down+= memo(m,n,i,j-1,dp);
        return dp[i][j] = right+down;
            
    }
    
    int tabu(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,1));
      
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            
        }
        return dp[m-1][n-1];
    }
    
    
    int uniquePaths(int m, int n) {
        // return recur(m,n,m-1,n-1);
        
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return memo(m,n,m-1,n-1,dp);
        
        return tabu(m,n);
    }
};