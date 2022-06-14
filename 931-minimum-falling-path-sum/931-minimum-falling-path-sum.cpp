class Solution {
public:
    
    
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<vector<int>> dummy(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dummy[n-1][i]=matrix[n-1][i];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                if(j==0)
                    dummy[i][j] = matrix[i][j] + min(dummy[i+1][j],dummy[i+1][j+1]);
                else if(j==n-1)
                    dummy[i][j] = matrix[i][j] + min(dummy[i+1][j],dummy[i+1][j-1]);
                else{
                    dummy[i][j] = matrix[i][j] + min(dummy[i+1][j],min(dummy[i+1][j+1],dummy[i+1][j-1]));
                }
            }
        }
        
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
            mini = min(mini,dummy[0][i]);
        
        
        return mini;
    }
};