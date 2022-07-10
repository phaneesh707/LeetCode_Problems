class Solution {
public:
    
    int recur(vector<vector<int>> a,int i,int j){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0 || a[i][j] == 1)
            return 0;
        int up=0,left = 0;
        up = recur(a,i-1,j);
        left = recur(a,i,j-1);
        
        return up+left;
        
    }
    
    int memo(vector<vector<int>> a,int i,int j,vector<vector<int>> dp){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0 || a[i][j] == 1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up=0,left = 0;
        up = memo(a,i-1,j,dp);
        left = memo(a,i,j-1,dp);
        
        return dp[i][j] = up+left;
        
    }
    
    
    int tabu(vector<vector<int>> a){
        int m = a.size(),n=a[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0  && a[i][j]!=1)
                    dp[i][j] = 1;
                else if(i==0 && j==0  && a[i][j]==1)
                    dp[i][j] = 0;
                else{
                    int up = 0,left = 0;
                    if(i>0 && a[i][j]!=1) up = dp[i-1][j];
                    if(j>0 && a[i][j]!=1) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        
        return dp[m-1][n-1];
        
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        
        // return recur(grid,m-1,n-1);
        
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return memo(grid,m-1,n-1,dp);
        
        return tabu(grid);
    }
};