class Solution {
public:
    
    string tabu(string s,string t){
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(s[idx1-1] == t[idx2-1])
                    dp[idx1][idx2] = 1 +dp[idx1-1][idx2-1];
                else
                    dp[idx1][idx2] =  max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
        
        
        int i = n,j = m;
        string str ="";
        while(i>0 && j>0){
            if(s[i-1] == t[j-1]){
                str+=s[i-1];
                i--;
                j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                str+=s[i-1];
                i--;
            }else{
                str+=t[j-1];
                j--;

            }      
        }
        
        
        if(i==0 & j!=0){
            while(j!=0){
                str+=t[j-1];
                j--;
            }
        }else if(j == 0 && i!=0){
            while(i!=0){
                str+=s[i-1];
                i--;
            }
        }
        
        
        reverse(str.begin(),str.end());
        return str;

}
    
    string shortestCommonSupersequence(string str1, string str2) {
        return tabu(str1,str2);
    }
};