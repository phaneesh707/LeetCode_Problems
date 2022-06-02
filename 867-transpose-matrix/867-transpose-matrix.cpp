class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(),n=matrix[0].size();
        vector<vector<int>> a(n,vector<int> (m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                a[j][i] = matrix[i][j];
            }
        }
        
        return a;
    }
};