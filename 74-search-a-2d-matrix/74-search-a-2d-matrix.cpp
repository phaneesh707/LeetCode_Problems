class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n=matrix[0].size();
        cout<<m<<n;
        int flag;
        for(int i=0;i<m;i++){
            if(target<=matrix[i][n-1]){
                int low = 0,high = n-1,mid;
                while(low<=high){
                    mid = (low+high)/2;
                    if(matrix[i][mid]==target){
                        return true;
                    }
                    else if(matrix[i][mid]>target)
                        high=mid-1;
                    else
                        low=mid+1;
                }
                flag = false;
            }
        }
        return flag;
    }
        
};