class Solution {
public:
    
    //time complexity - O(n*n);
    
    bool valid(int i,int j,int n){
        if(i>=0 && j>=0 && i<n && j<n)
            return true;
        return false;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n,vector<int>(n));
        int count = 1,i=0,j=0;
        
        
        while(count<=n*n){
            //going right and filling 
            while(valid(i,j,n) && !grid[i][j]){
                grid[i][j] = count++;
                j++;
            }
            if(!valid(i,j,n)|| grid[i][j])
                j--;
            i++;
            
            
            
            //going down & filling
            while(valid(i,j,n) && !grid[i][j]){
                grid[i][j] = count++;
                i++;
            }
            //backtrack to previous grid if its out of bound or its already filled
            if(!valid(i,j,n) || grid[i][j])
                i--;
            j--;
            if(count>n*n)
                break;
            
            
            //going left & filling
            while(valid(i,j,n) && !grid[i][j]){
                grid[i][j] = count++;
                j--;
            }
            if(!valid(i,j,n) || grid[i][j])
                j++;
            i--;
            if(count>n*n)
                break;
            
            // going up and filling 
            while(valid(i,j,n) && !grid[i][j]){
                grid[i][j] = count++;
                i--;
            }
            if(!valid(i,j,n) || grid[i][j])
                i++;
            j++;
            if(count>n*n)
                break;
           
                        
        }
        
        return grid;
    }
};