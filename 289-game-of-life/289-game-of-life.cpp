class Solution {
public:
    
    
    //time complexity = O(m*n)
    //space commplexity =O(m*n)
    
    bool valid(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
        
    }
    
    int gimmeCount(vector<vector<int>> board,int i,int j){
        
        int m = board.size();
        int n = board[0].size();
        int count=0;
        
        //counting the number of 1's in the neighbour of board[i][j];
        
        if(valid(i,j+1,m,n) && board[i][j+1])
            count++;
         if(valid(i+1,j+1,m,n) && board[i+1][j+1])
            count++;
         if(valid(i+1,j,m,n) && board[i+1][j])
            count++;
         if(valid(i+1,j-1,m,n) && board[i+1][j-1])
            count++;
         if(valid(i,j-1,m,n) && board[i][j-1])
            count++;
        if(valid(i-1,j-1,m,n) && board[i-1][j-1])
            count++;
         if(valid(i-1,j,m,n) && board[i-1][j])
            count++;
         if(valid(i-1,j+1,m,n) && board[i-1][j+1])
            count++;
            
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> newB(m,vector<int>(n));
        newB=board;
        
        
        //traversing thru the board and updating the new board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
        
                int count = gimmeCount(newB,i,j);
                if(newB[i][j]==1){                
                    if(count<2)
                        board[i][j] = 0;
                    else if(count == 2 || count == 3)
                        board[i][j] = 1;
                    else if(count>3)
                        board[i][j] = 0;
                
                }else if(!newB[i][j] && count==3)
                    board[i][j]=1;
            }
        }
        
    }
};