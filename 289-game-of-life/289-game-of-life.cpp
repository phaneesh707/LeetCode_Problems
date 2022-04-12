class Solution {
public:
    
    bool valid(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
        
    }
    
    int gimmeCount(vector<vector<int>> Board,int i,int j){
        
        int m = Board.size();
        int n = Board[0].size();
        int count=0;
        
        
        
        if(valid(i,j+1,m,n) && Board[i][j+1])
            count++;
        else if(valid(i+1,j+1,m,n) && Board[i+1][j+1])
            count++;
        else if(valid(i+1,j,m,n) && Board[i+1][j])
            count++;
        else if(valid(i+1,j-1,m,n) && Board[i+1][j-1])
            count++;
        else if(valid(i,j-1,m,n) && Board[i][j-1])
            count++;
        else if(valid(i-1,j-1,m,n) && Board[i-1][j-1])
            count++;
        else if(valid(i-1,j,m,n) && Board[i-1][j])
            count++;
        else if(valid(i-1,j+1,m,n) && Board[i-1][j+1])
            count++;
            
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> newB(m,vector<int>(n));
        // auto newB(board);
        // newB=board;
         
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               
                for(int k = 0;k<m;k++){
                for(int l=0;l<n;l++){
                    cout<<board[k][l];
                }
            }
                
                cout<<"------new = ";
                for(int k = 0;k<m;k++){
                for(int l=0;l<n;l++){
                    cout<<newB[k][l];
                }
            }
                
                
                
                // -------------------------------------
                int count=0;
        
        
        
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
                // ---------------------------------------
                
                
                
                // int count = gimmeCount(board,i,j);
                cout<<"\n";
                if(board[i][j]==1){                
                    if(count<2)
                        newB[i][j] = 0;
                    else if(count == 2 || count == 3)
                        newB[i][j] = 1;
                    else if(count>3)
                        newB[i][j] = 0;
                
                }else if(!board[i][j] && count==3)
                    newB[i][j]=1;
            }
        }
        
        
        board = newB;
//         for(int k = 0;k<m;k++){
//                 for(int l=0;l<n;l++){
//                     cout<<newB[k][l];
//                 }
//             }
        

    }
};