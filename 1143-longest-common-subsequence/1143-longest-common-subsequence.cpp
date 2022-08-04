class Solution {
public:
    
    int recur(string s, string t,int idx1,int idx2){
        if(idx1<0 || idx2<0)
            return 0;
        if(s[idx1] == s[idx2])
            return 1 + recur(s,t,idx1-1,idx2-1);
        return max(recur(s,t,idx1-1,idx2),recur(s,t,idx1,idx2-1));
    }
    
    int memo(string s, string t,int idx1,int idx2,vector<vector<int>>& dp){
        if(idx1<0 || idx2<0)
            return 0;

        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];

        if(s[idx1] == t[idx2])
            return dp[idx1][idx2] = 1 + memo(s,t,idx1-1,idx2-1,dp);
        return dp[idx1][idx2] = max(memo(s,t,idx1-1,idx2,dp),memo(s,t,idx1,idx2-1,dp));
    }
    
    int tabu(string s, string t,int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = (s[0]==t[0]);
        
        for(int i=1;i<n;i++){
            if(s[0] == t[i])
                dp[0][i] = 1;
            else 
                dp[0][i] = dp[0][i-1];
                
        }
        
        for(int i=1;i<m;i++){
            if(t[0] == s[i])
                dp[i][0] = 1;
            else 
                dp[i][0] = dp[i-1][0];
                
        }
        
        for(int idx1=1;idx1<m;idx1++){
            for(int idx2=1;idx2<n;idx2++){
                
                if(s[idx1] == t[idx2])
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                else
                    dp[idx1][idx2] = max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
        return dp[m-1][n-1];
        
        
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return recur(text1,text2,m-1,n-1);   
        // return memo(text1,text2,m-1,n-1,dp);
        return tabu(text1,text2,m,n);
    }
};