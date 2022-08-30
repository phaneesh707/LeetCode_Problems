class Solution {
public:
    
    vector<int> d = {0,1,0,-1,0};
    
    int dfs(vector<vector<int>> a,int i,int j,vector<vector<int>>& visited){
        int m = size(a),n = size(a[0]);
        visited[i][j] = 1;
        int maxi = 1;
        for(int k=0;k<4;k++){
            int x = i + d[k];
            int y = j + d[k+1];
            if(x>=0 && x<m && y>=0 && y<n && a[x][y] == 1 && !visited[x][y])
                maxi +=dfs(a,x,y,visited);
        }
        
        return maxi;
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = size(grid),n = size(grid[0]),maxi = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    maxi = max(maxi,dfs(grid,i,j,visited));
                }
            }
        }
        
        return maxi;
    }
};