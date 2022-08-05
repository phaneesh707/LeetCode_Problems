class Solution {
public:
    
    int recur(string s,string t,int idx1,int idx2){
        if(idx1<0 || idx2<0)
            return 0;
        if(s[idx1] == t[idx2])
            return 1+recur(t,s,idx1-1,idx2-1);
        
        return max(recur(s,t,idx1-1,idx2),recur(s,t,idx1,idx2-1));
    }
    
    int tabu(string s,string t,int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=n;idx2++){
                if(s[idx1-1] == t[idx2-1])
                    dp[idx1][idx2] =  1+dp[idx1-1][idx2-1];
                else
                    dp[idx1][idx2] = max(dp[idx1-1][idx2],dp[idx1][idx2-1]);   
            }
        }
        
        // for(int idx1=0;idx1<=n;idx1++){
        //     for(int idx2=0;idx2<=n;idx2++){
        //         cout<<dp[idx1][idx2]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[n][n];
    }
    
    int spaceOpti(string s,string t,int n){
        vector<int> pres(n+1,0),prev(n+1,0);
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=n;idx2++){
                if(s[idx1-1] == t[idx2-1])
                    pres[idx2] =  1+prev[idx2-1];
                else
                    pres[idx2] = max(prev[idx2],pres[idx2-1]);   
            }
            prev = pres;
        }
        
        return prev[n];
    }
    
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        int n = s.size();
        reverse(t.begin(),t.end());
        // return recur(s,t,n-1,n-1);
        // return tabu(s,t,n);
        return spaceOpti(s,t,n);
    }
};