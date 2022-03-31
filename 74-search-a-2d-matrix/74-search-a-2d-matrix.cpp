class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // complexity - nlog(n)
        int n=matrix[0].size();
        bool flag;
        // traversing thru all array by checking its last ele and then binary src 
        for(int i=0;i<matrix.size();i++){
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