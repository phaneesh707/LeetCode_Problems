class Solution {
public:
    
    
    int noAttack(vector<string> str,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(str[row][i]=='Q' || str[i][col]=='Q')
                return 0;
        }
        int i = row,j = col;
        while(--i>=0 && ++j<n){
            if(str[i][j]=='Q')
                return 0;
        }
        i = row;
        j = col;
        while(--i>=0 && --j>=0){
            if(str[i][j]=='Q')
                return 0;
        }
        
        return 1;
    }
    
    void solve(vector<vector<string>>& a,vector<string> str,int n,int level,int count){
        if(n==count){
            a.push_back(str);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(noAttack(str,level,i,n)){
                str[level][i]='Q';
                count++;
                solve(a,str,n,level+1,count);
                count--;
                str[level][i]='.';
            }
        }
        
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> str;
        string s;
        for(int i=0;i<n;i++){
            s.push_back('.');
        }
        for(int i=0;i<n;i++){
            str.push_back(s);
        }
        
        
        vector<vector<string>> a;
        solve(a,str,n,0,0);
        
        
        return a;
    }
};