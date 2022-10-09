class Solution {
public:
    long long mod = 1e9+7;
//     int recur(vector<vector<int>> a,int i,int j,int sum,int k){
//         if(i<0 || j<0)
//             return 0;
        
//         if(i==0 && j==0){
//             sum+=a[0][0];
//             return sum%k==0;
//         }
        
//         int left = recur(a,i,j-1,(sum+a[i][j])%k,k);
//         int right = recur(a,i-1,j,(sum+a[i][j])%k,k);
//         return left+right;
        
//     }
    
    int memo(vector<vector<int>>& a,int i,int j,int sum,int k,vector<vector<vector<int>>>& dp){
        if(i<0 || j<0)
            return 0;
        if(i==0 && j==0){
            sum+=a[0][0];
            return sum%k==0;
        }
        
        if(dp[i][j][sum%k]!=-1)
            return dp[i][j][sum];
        
        int left = memo(a,i,j-1,(sum+a[i][j])%k,k,dp)%mod;
        int right = memo(a,i-1,j,(sum+a[i][j])%k,k,dp)%mod;
        return dp[i][j][sum%k] = (left+right)%mod;
        
    }
    
    
//     int tabu(vector<vector<int>> a,int k){
//         int m = size(a),n=size(a[0]);
//         vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k,0)));
//         // for(int i=0;i<k;i++){
//         //     dp[1][1][i] = (i+a[0][0])%k==0; 
//         // }
//         dp[1][1][a[0][0]%k] = (a[0][0]%k==0);
//         for(int i=1;i<=m;i++){
//             for(int j=1;j<=n;j++){
//                 for(int sum=0;sum<k;sum++){
//                     int left = dp[i][j-1][(sum+a[i-1][j-1])%k];
//                     int right = dp[i-1][j][(sum+a[i-1][j-1])%k];
//                     dp[i][j][sum] = (left+right)%mod;
//                 }
//             }
//         }
        
//         int sum = 0;
//         return dp[m][n][0];
        
//     }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int m = size(grid),n=size(grid[0]);
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(51,-1)));
        // vector<vector<<int>> dp(m,vector<int>(n-1));
        // return recur(grid,m-1,n-1,0,k);
        return memo(grid,m-1,n-1,0,k,dp);
        
        // return tabu(grid,k);
    }
};