class Solution {
public:
    
    int isValid(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;
        return 1;
    }
    
    
    void dfs(vector<vector<int>>& a,vector<vector<int>>& visited,int i,int j,int color){
        int m = size(a),n = size(a[0]),curr = a[i][j];
        visited[i][j] = 1;
        a[i][j] = color;
        // cout<<isValid(i-1,j,m,n)<<(a[i][j] == a[i-1][j])<<(!visited[i-1][j]);
        if(isValid(i-1,j,m,n) && curr == a[i-1][j] && !visited[i-1][j])
            dfs(a,visited,i-1,j,color);
        if(isValid(i,j+1,m,n) &&  curr == a[i][j+1] && !visited[i][j+1])
            dfs(a,visited,i,j+1,color);
        if(isValid(i+1,j,m,n) && curr == a[i+1][j] && !visited[i+1][j])
            dfs(a,visited,i+1,j,color);
        if(isValid(i,j-1,m,n) &&  curr == a[i][j-1] && !visited[i][j-1])
            dfs(a,visited,i,j-1,color);
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = size(image),n = size(image[0]);
        vector<vector<int>> visited(m,vector<int>(n,0));
        dfs(image,visited,sr,sc,color);
        return image;
    }
};