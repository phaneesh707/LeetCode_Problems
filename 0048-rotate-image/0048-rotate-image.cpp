class Solution {
public:
    
    void swap(int& a,int &b){
        int temp = a;
        a = b;
        b = temp;
        return;
    }
    
    void rotate(vector<vector<int>>& a) {
        int n = size(a);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++)
                swap(a[i][j],a[j][i]); 
        }
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<n/2;j++)
                swap(a[i][j],a[i][n-j-1]);
            
        }
        return;
    }
};