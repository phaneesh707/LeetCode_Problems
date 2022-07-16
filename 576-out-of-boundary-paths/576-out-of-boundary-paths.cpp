class Solution {
public:
    int recur(int m,int n,int maxMove,int i,int j){
        if(i>m || j>n || i<0 || j<0)
            return 1;
            
        if(maxMove==0)
            return 0;
        
        
        int l=0,r=0,u=0,d=0;
        l=recur(m,n,maxMove-1,i,j-1);
        u=recur(m,n,maxMove-1,i-1,j);
        r=recur(m,n,maxMove-1,i,j+1);
        d=recur(m,n,maxMove-1,i+1,j);
        return l+r+u+d;
    }
    
    int memo(int m,int n,int maxMove,int i,int j,vector<vector<vector<int>>> dp){
        if(i>m || j>n || i<0 || j<0)
            return 1;
            
        if(maxMove<0)
            return 0;
            
        if(dp[i][j][maxMove]!=-1)
            return dp[i][j][maxMove];
        
        int l=0,r=0,u=0,d=0;
        l=memo(m,n,maxMove-1,i,j-1,dp)%mod;
        u=memo(m,n,maxMove-1,i-1,j,dp)%mod;
        r=memo(m,n,maxMove-1,i,j+1,dp)%mod;
        d=memo(m,n,maxMove-1,i+1,j,dp)%mod;
        return dp[i][j][maxMove] = (l+r+u+d)%mod;
    }
    
    const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool outOfBounds(int m, int n, int r, int c) {
	    return r < 0 || r >= m || c < 0 || c >= n;
    }
    int tabu(int m, int n, int maxMove, int r, int c) {
        auto outOfBounds = [&](int m, int n, int r, int c){return r < 0 || r >= m || c < 0 || c >= n;};
        uint dp[50][50][2]{};        
        for(int M = 1; M <= maxMove; M++)
            for(int i = 0; i < m; i++) 
                for(int j = 0, k; j < n; j++) 
                    for(k = 0, dp[i][j][M & 1] = 0; k < 4; k++) 
                        if(outOfBounds(m, n, i + moves[k][0], j + moves[k][1])) dp[i][j][M & 1]++;
                        else dp[i][j][M & 1] += dp[i + moves[k][0]][j + moves[k][1]][(M-1) & 1] % mod;
        return dp[r][c][maxMove & 1] % mod;
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // return recur(m-1,n-1,maxMove,startRow,startColumn)%mod;
        
        // vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove,-1)));
        // return memo(m-1,n-1,maxMove-1,startRow,startColumn,dp);
        
        return tabu(m,n,maxMove,startRow,startColumn);
        
    }
};