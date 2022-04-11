class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(k%(m*n)==0)
            return grid;
        
        k%=(m*n);
        int count=0;
        vector<int> s;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                s.push_back(grid[i][j]);
        }
        
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