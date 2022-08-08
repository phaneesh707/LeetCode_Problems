// class Solution {
// public:
    
//     int recur(string s, string t,int idx1,int idx2){
//         if(idx2>=0 && idx1<0)
//             return 0;
//         if(idx2<0 && idx1>=-1)
//             return 1;
        
//         int take = 0,notTake = 0;
//         if(s[idx1] == t[idx2])
//             take = recur(s,t,idx1-1,idx2-1);
//         else 
//             notTake = recur(s,t,idx1-1,idx2);
//         return take + notTake;
            
//     }
    
    
//     int tabu(string s, string t){
//         int n = s.size(),m = t.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         for(int i=0;i<=n;i++)
//             dp[i][0] = 1;
        
        
//         for(int idx1=1;idx1<=n;idx1++){
//             for(int idx2=1;idx2<=m;idx2++){
                
//                 int take = 0,notTake = 0;
//                 if(s[idx1-1] == t[idx2-1])
//                     take = dp[idx1-1][idx2-1];
//                 else 
//                     notTake = dp[idx1-1][idx2];
//                 dp[idx1][idx2] = take + notTake;
//             }
//         }
    
        
//         return dp[n][m];
//     }
    
    
//     int numDistinct(string s, string t) {
//         int n = s.size(),m = t.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         // return recur(s,t,n-1,m-1);
//         // return memo(s,t,n-1,m-1,dp);
//         return tabu(s,t);
//     }
// };




class Solution {
public:
    
    int recur(string s, string t,int idx1,int idx2){
        if(idx2<0) return 1;
        if(idx1<0) return 0;
        
        
        if(s[idx1] == t[idx2])
            return recur(s,t,idx1-1,idx2-1) + recur(s,t,idx1-1,idx2);
        else
            return recur(s,t,idx1-1,idx2);
    }
    
    int tabu(string s, string t){
        int n = s.size(),m = t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        
        
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                
                if(s[idx1-1] == t[idx2-1])
                    dp[idx1][idx2] =  dp[idx1-1][idx2-1] + dp[idx1-1][idx2];
                else
                    dp[idx1][idx2] =  dp[idx1-1][idx2];
            }
        }
    
        
        return (int)dp[n][m];
    }
    
    
    int spaceOpti(string s, string t){
        int n = s.size(),m = t.size();
        vector<double> dp(m+1,0);
        dp[0] = 1;
        
        
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=m;idx2>=1;idx2--){
                
                if(s[idx1-1] == t[idx2-1])
                    dp[idx2] =  dp[idx2-1] + dp[idx2];
                else
                    dp[idx2] =  dp[idx2];
            }
        }
    
        
        return (int)dp[m];
    }
    
    int numDistinct(string s, string t) {
        int n = s.size(),m = t.size();
        // return recur(s,t,n-1,m-1);
        // return tabu(s,t);
        return spaceOpti(s,t);
    }
};


