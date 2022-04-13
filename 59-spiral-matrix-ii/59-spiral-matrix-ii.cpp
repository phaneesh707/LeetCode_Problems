class Solution {
public:
    bool valid(int i,int j,int n){
        if(i>=0 && j>=0 && i<n && j<n)
            return true;
        return false;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n,vector<int>(n));
        int count = 1,i=0,j=0;
        
        
        while(count<=n*n){
            //going right
            while(valid(i,j,n) && !grid[i][j]){
                grid[i][j] = count++;
                j++;
            }
            if(!valid(i,j,n)|| grid[i][j])
                j--;
            i++;
            cout<<"i="<<i<<"j="<<j<<"\n";
            
            
            
            //going down
            while(valid(i,j,n) && !grid[i][j]){
                grid[i][j] = count++;
                i++;
            }
            if(!valid(i,j,n) || grid[i][j])
                i--;
            j--;
            cout<<"i="<<i<<"j="<<j<<"\n";
            if(count>n*n)
                break;
            
            
            //going left
            while(valid(i,j,n) && !grid[i][j]){
                grid[i][j] = count++;
                j--;
            }
            if(!valid(i,j,n) || grid[i][j])
                j++;
            i--;
            if(count>n*n)
                break;
            cout<<"i="<<i<<"j="<<j<<"\n";
            if(count>n*n)
                break;
            
            
            
            
            // going up
            while(valid(i,j,n) && !grid[i][j]){
                grid[i][j] = count++;
                i--;
            }
            if(!valid(i,j,n) || grid[i][j])
                i++;
            j++;
            cout<<"i="<<i<<"j="<<j<<"\n";
            if(count>n*n)
                break;
            
            
            for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
            cout<<"\n";
            
        }
        
        return grid;
    }
};