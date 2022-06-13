class Solution {
public:
    //recursive - TLE
    // int cal(vector<vector<int>> tri,int row,int col){
    //     if(row==tri.size())
    //         return 0;
    //     return tri[row][col] + min(cal(tri,row+1,col),cal(tri,row+1,col+1));
    // }
    
    int cal2(vector<vector<int>> tri){
        int n = tri.size();
        vector<int> a(n,0);
        for(int i=0;i<n;i++)
            a[i] = tri[n-1][i];
        
        for(int i = n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                a[j] = tri[i][j] + min(a[j],a[j+1]);
            }
        }
        return a[0];
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size();
        // vector<vector<int>> dummy(n,vector<int>(n,0));
        // for(int j=0;j<n;j++)
        //     dummy[n-1][j] = triangle[n-1][j];
        // for(int i=n-2;i>=0;i--){
        //         for(int j = i;j>=0;j--){
        //             dummy[i][j] = triangle[i][j] + min(dummy[i+1][j],dummy[i+1][j+1]);
        //         }
        // }
        // return dummy[0][0];
        
        return cal2(triangle);
    }
};