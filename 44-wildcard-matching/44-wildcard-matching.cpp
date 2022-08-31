class Solution {
public:
//     int recur(string s,string p,int i,int j,int flag){
        
//         if(j<0){
//             if(i<0 || flag)
//                 return 1;
//             return 0;
//         }
        
//         if(i<0){
//             while(j>=0){
//                 if(p[j]!='*')
//                     return 0;
//                 j--;
//             }
//             return 1;
//         }
        
//         if(s[i] == p[j])
//             return recur(s,p,i-1,j-1,0);
//         else{
//             if(p[j] == '*')
//                 return recur(s,p,i,j-1,1);
//             else if(p[j] == '?' && flag)
//                 return recur(s,p,i,j-1,flag);
//             else if(p[j]=='?')
//                 return recur(s,p,i-1,j-1,0);
//             else if(flag)
//                 return recur(s,p,i-1,j,flag);
           
//         }
//         return 0;
//     }
    
    
    int recur(string s,string p,int i,int j){
        
        if(j<0 && i<0) return 1;
        if(j<0 && i>=0) return 0;
        
        if(i<0){
            while(j>=0){
                if(p[j]!='*')
                    return 0;
                j--;
            }
            return 1;
        }
        
        
        if(s[i] == p[j] || p[j] == '?')
            return recur(s,p,i-1,j-1);
        if(p[j] =='*')
            return recur(s,p,i,j-1) || recur(s,p,i-1,j);
        
        return 0;
        
    }
    
    
    int memo(string s,string p,int i,int j,vector<vector<int>>& dp){
        
        if(j<0 && i<0) return 1;
        if(j<0 && i>=0) return 0;
        
        if(i<0){
            while(j>=0){
                if(p[j]!='*')
                    return 0;
                j--;
            }
            return 1;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = memo(s,p,i-1,j-1,dp);
        if(p[j] =='*')
            return dp[i][j] = memo(s,p,i,j-1,dp) || memo(s,p,i-1,j,dp);
        
        return dp[i][j] = 0;
        
    }
    
    int tabu(string s,string p){
        int m = size(s),n = size(p);
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*')
                dp[0][i] = 1;
            else
                break;
        }
        
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] =='*')
                    dp[i][j] =dp[i][j-1] || dp[i-1][j];
                else
                    dp[i][j] = 0;
            }
        }
        
        return dp[m][n];
        
        
    }
    
    
    int spaceOpti(string s,string p){
        int m = size(s),n = size(p);
        vector<int> pres(n+1,0),prev(n+1,0);
        prev[0] = 1;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*')
                prev[i] = 1;
            else
                break;
        }
        
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    pres[j] = prev[j-1];
                else if(p[j-1] =='*')
                    pres[j] = pres[j-1] || prev[j];
                else
                    pres[j] = 0;
            }
            prev = pres;
        }
        
        return prev[n];
        
        
    }
    
    bool isMatch(string s, string p) {
        int m = size(s),n = size(p);
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return recur(s,p,m-1,n-1);
        // return memo(s,p,m-1,n-1,dp);
        // return tabu(s,p);
        return spaceOpti(s,p);
    }
};