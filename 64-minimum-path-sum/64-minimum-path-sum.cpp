class Solution {
public:
    
    int recur(vector<vector<int>> a,int i,int j){
        if(i==0 && j==0)
            return a[0][0];

        int up=INT_MAX,left=INT_MAX;
        if(i>0 && j>=0)
            up = a[i][j] + recur(a,i-1,j);
        if(j>0 && i>=0)
            left = a[i][j] + recur(a,i,j-1);
        
        return min(up,left);
        
    }
    
    int memo(vector<vector<int>> a,int i,int j,vector<vector<int>> dp){
        if(i==0 && j==0)
            return a[0][0];

        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        int up=INT_MAX,left=INT_MAX;
        if(i>0 && j>=0)
            up = a[i][j] + memo(a,i-1,j,dp);
        if(j>0 && i>=0)
            left = a[i][j] + memo(a,i,j-1,dp);
        
        return dp[i][j] =  min(up,left);
        
    }
    
    
    int tabu(vector<vector<int>> a){
        int m=a.size(),n=a[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0] = a[0][0];
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i || j){
                    int right=INT_MAX,down=INT_MAX;
                    if(i>0 && j>=0)
                        down = a[i][j] + dp[i-1][j];
                    if(j>0 && i>=0)
                        right = a[i][j] + dp[i][j-1];
                    dp[i][j] = min(down,right);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        // return recur(grid,m-1,n-1);
        
        // vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        // return memo(grid,m-1,n-1,dp);
        
        return tabu(grid);
    }
};