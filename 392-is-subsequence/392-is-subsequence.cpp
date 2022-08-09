class Solution {
public:
    
    int recur(string s, string t,int i,int j){
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        
        if(s[i] == t[j])
            return recur(s,t,i-1,j-1);
        else
            return recur(s,t,i-1,j);
        
    }
    
    
    int tabu(string s, string t,int n,int m){
        vector<int> pres(m+1,0),prev(m+1,0);
        prev[0] = pres[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1])
                    pres[j] =  prev[j-1];
                else
                    pres[j] = prev[j];
            }
            prev = pres;
        }
        
        return prev[m];
    }
    
    bool isSubsequence(string s, string t) {
        int n = s.size(),m = t.size();
        // return recur(t,s,m-1,n-1);
        return tabu(t,s,m,n);
        
    }
};