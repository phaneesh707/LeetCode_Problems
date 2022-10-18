class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = size(matrix),n = size(matrix[0]);
        vector<int> col;
        vector<int> row;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        
        for(auto it:row){
            for(int i=0;i<n;i++)
                matrix[it][i] = 0;
        }
        
        for(auto it:col){
            for(int i=0;i<m;i++)
                matrix[i][it] = 0;
        }
        
    
    }
};