class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        //size of matrix
        int m = grid.size();
        int n = grid[0].size();
        if(k%(m*n)==0)
            return grid;
        
        //if size of matrix is equal to k then no change 
        k%=(m*n);
        int count=0;
        vector<int> s;
        
        //storing the grid value in vector
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                s.push_back(grid[i][j]);
        }
        
        
        //starting from the shift position ,start inserting into grid 
        count = s.size()-k;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = s[count];
                ++count;
                if(count==s.size())
                    count=0;
                
                if(count== s.size()-k)
                    break;
            }
        }    
        
        return grid;
    }
};