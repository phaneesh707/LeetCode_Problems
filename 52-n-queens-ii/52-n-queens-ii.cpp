class Solution {
public:
    
    //checking if queen is safe 
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
    
    void solve(vector<string> str,int n,int level,int&sol){
        if(n==level){
            sol++;
            return;
        }
        
        for(int i=0;i<n;i++){
            //cheking if any ohter queen can attack or no
            if(noAttack(str,level,i,n)){
                str[level][i]='Q';//place the queen & move to next row
                solve(str,n,level+1,sol);
                str[level][i]='.';//remove queen
            }
        }
        
        
    }
   
    int totalNQueens(int n) {
        //generating the board;
        vector<string> str;
        string s;
        for(int i=0;i<n;i++){
            s.push_back('.');
        }
        for(int i=0;i<n;i++){
            str.push_back(s);
        }
        
        //backtarck
        int sol=0;
        solve(str,n,0,sol);
        return sol;
        
    }
};