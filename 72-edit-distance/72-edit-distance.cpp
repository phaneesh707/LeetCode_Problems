class Solution {
public:
    
    int recur(string s,string t,int i,int j){
        if(j<0)
            return i+1;
        if(i<0)
            return j+1;
        
        if(s[i] == t[j])
            return recur(s,t,i-1,j-1);
        else{
            int delet = 1 + recur(s,t,i-1,j);
            int replace = 1 + recur(s,t,i-1,j-1);
            int insert = 1 + recur(s,t,i,j-1);
            return min({delet,replace,insert});
        }
    }
    
    int tabu(string s,string t,int n,int m){
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0] = i;
        for(int i=0;i<=m;i++)
            dp[0][i] = i;
        
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] =  dp[i-1][j-1];
                else{
                    int delet = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];
                    int insert = 1 +dp[i][j-1];
                    dp[i][j] = min({delet,replace,insert});
                }
                     
            }
        }
        
         return dp[n][m];
    }
    
    
    int spaceOpti(string s,string t,int n,int m){
        vector<int> prev(m+1,0),pres(m+1,0);
        
        for(int i=0;i<=m;i++)
            prev[i] = i;
        
        for(int i = 1;i<=n;i++){
            pres[0] = i;
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1])
                    pres[j] =  prev[j-1];
                else{
                    int delet = 1 + prev[j];
                    int replace = 1 + prev[j-1];
                    int insert = 1 + pres[j-1];
                    pres[j] = min({delet,replace,insert});
                }
                     
            }
            prev = pres;
        }
        
         return prev[m];
    }
    
    int minDistance(string word1, string word2) {
        int n = size(word1),m = size(word2);
        // return recur(word1,word2,n-1,m-1);
        // return tabu(word1,word2,n,m);
        return spaceOpti(word1,word2,n,m);
    }
};