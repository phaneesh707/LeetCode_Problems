class Solution {
public:
    int isValid(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;
        return 1;
    }
    
    void bfs(vector<vector<int>>& a,vector<vector<int>>& visited,vector<pair<int,int>> r,vector<vector<int>>& level){
        int m = size(a),n = size(a[0]);
        queue<pair<int,int>> q;
        for(auto it:r){
            visited[it.first][it.second] = 1;
            q.push(it);
        }
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(isValid(i-1,j,m,n) && a[i-1][j]==1 && !visited[i-1][j]){
                visited[i-1][j] = 1;
                a[i-1][j] = 2;
                q.push({i-1,j});
                level[i-1][j] = level[i][j]+1;
            }

            if(isValid(i,j+1,m,n) &&  a[i][j+1]==1 && !visited[i][j+1]){
                visited[i][j+1] = 1;
                a[i][j+1] = 2;
                q.push({i,j+1});
                level[i][j+1] = level[i][j]+1;
            }

            if(isValid(i+1,j,m,n) && a[i+1][j]==1 && !visited[i+1][j]){
                visited[i+1][j] = 1;
                a[i+1][j] = 2;
                q.push({i+1,j});
                level[i+1][j] = level[i][j]+1;
            }

            if(isValid(i,j-1,m,n) &&  a[i][j-1]==1  && !visited[i][j-1]){
                 visited[i][j-1] = 1;
                a[i][j-1] = 2;
                q.push({i,j-1});
                level[i][j-1] = level[i][j]+1;
            }
        }
            
        
    }
    
    
//     void dfs(vector<vector<int>>& a,vector<vector<int>>& visited,vector<vector<int>>& level){
//         int m = size(a),n = size(a[0]);
//         visited[i][j] = 1;
//         a[i][j] = 2;
//         if(isValid(i-1,j,m,n) && a[i-1][j]==1 && !visited[i-1][j]){
//                 k=max(k,count+1);
//                 dfs(a,visited,i-1,j,count+1,k);
//         }
                
//         if(isValid(i,j+1,m,n) &&  a[i][j+1]==1 && !visited[i][j+1]){
//              k=max(k,count+1);
//             dfs(a,visited,i,j+1,count+1,k);
//         }
        
//         if(isValid(i+1,j,m,n) && a[i+1][j]==1 && !visited[i+1][j]){
//              k=max(k,count+1);
//             dfs(a,visited,i+1,j,count+1,k);
//         }
        
//         if(isValid(i,j-1,m,n) &&  a[i][j-1]==1  && !visited[i][j-1]){
//              k=max(k,count+1);
//             dfs(a,visited,i,j-1,count+1,k);
//         }
        
        
//     }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = size(grid),n = size(grid[0]),maxi = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> level(m,vector<int>(n,0));
        vector<pair<int,int>> r;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    // bfs(grid,visited,level);
                    r.push_back({i,j});
                }
                
            }
        }
        bfs(grid,visited,r,level);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<
                if(grid[i][j] == 1)
                    return -1;
                maxi = max(level[i][j],maxi);
            }
        }
        
        return maxi;
    }
};