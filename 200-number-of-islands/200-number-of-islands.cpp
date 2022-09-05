class Solution {
public:
    
    int isValid(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;
        return 1;
            
    }
    
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        
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
    
    vector<int> d = {0,1,0,-1,0};
    void cleanDFS(vector<vector<char>>& a,vector<vector<int>>& visited,int i,int j){     
        visited[i][j] = 1;
        for(int k=0;k<4;k++){
            int x = i+d[k];
            int y = j+d[k+1];
            if(isValid(x,y,size(a),size(a[0])) && !visited[x][y] && a[x][y]=='1')
                cleanDFS(a,visited,x,y);
        }
        
    }
   
    int numIslands(vector<vector<char>>& grid){
        int n = size(grid),m = size(grid[0]),count = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    // cout<<i<<" "<<j<<endl;
                    cleanDFS(grid,visited,i,j);
                    // dfs(grid,visited,i,j);
                }     
            }
        }
        
        return count;
    }
};