class Solution {
public:
    
    int isValid(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;
        return 1;
            
    }
    
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        cout<<"recur "<<i<<" "<<j<<endl;
        int m = size(grid),n = size(grid[0]);
        visited[i][j] = 1;
        if(isValid(i-1,j,m,n) && grid[i-1][j]=='1' && !visited[i-1][j])
            dfs(grid,visited,i-1,j);
        if(isValid(i,j+1,m,n) && grid[i][j+1]=='1' && !visited[i][j+1])
            dfs(grid,visited,i,j+1);
        if(isValid(i+1,j,m,n) && grid[i+1][j]=='1' && !visited[i+1][j])
            dfs(grid,visited,i+1,j);
        if(isValid(i,j-1,m,n) && grid[i][j-1]=='1' && !visited[i][j-1])
            dfs(grid,visited,i,j-1);
        
    }
    
   
    int numIslands(vector<vector<char>>& grid){
        int n = size(grid),m = size(grid[0]),count = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<i<<" "<<j<<endl;
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    dfs(grid,visited,i,j);
                }     
            }
        }
        
        return count;
    }
};