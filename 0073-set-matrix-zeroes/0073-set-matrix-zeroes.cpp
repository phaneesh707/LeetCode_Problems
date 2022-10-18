class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = size(matrix),n = size(matrix[0]);
        int id = 1e9+7;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0)
                    matrix[i][j] = id;    
                
            }
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == id){
                    matrix[i][j] = 0;
                    for(int k = 0;k<n;k++){
                        if(matrix[i][k]!=id)
                            matrix[i][k] = 0;
                    }
                    
                    for(int k = 0;k<m;k++){
                        if(matrix[k][j]!=id)
                            matrix[k][j] = 0;
                    }
                }
                       
                
            }
        }
        
        
        
        
    
    }
};