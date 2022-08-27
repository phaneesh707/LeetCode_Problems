class Solution {
public:
    int LCS(string s,string p){
        int n = size(s),m = size(p);
        vector<int> pres(m+1,0),prev(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i] == p[j])
                    pres[j] = 1+prev[j-1];
                else
                    pres[j] = max(prev[j],pres[j-1]);
            }
            prev = pres;
        }
        return prev[m];
    }
    
    int cmp(string s,string p){
        int n = size(s),m = size(p),i=0,j=0;
        while(i<n && j<m){
            if(s[i] == p[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(j==m)
            return 1;
        return 0;
        
    }
    
    static bool compare(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    
    int LSC(vector<string> a){
        int n = size(a),maxi = 1;
        sort(a.begin(),a.end(),compare);
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(size(a[i])-size(a[j])==1 && cmp(a[i],a[j])){
                    dp[i] = max(dp[i],1+dp[j]);
                }
                
            }
            maxi = max(dp[i],maxi);
        }

        
        return maxi;
    }
    
    int longestStrChain(vector<string>& words) {
          return LSC(words); 
    }
};