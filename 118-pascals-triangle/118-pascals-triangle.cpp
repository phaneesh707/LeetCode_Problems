class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> temp;
    
        for(int i=0;i<numRows;i++){
            vector<int> dummy(i+1,1);
            for(int j=0;j<i;j++){
                if(j!=0)
                    dummy[j] = temp[i-1][j] + temp[i-1][j-1];
            }
            
            temp.push_back(dummy);
        }
        
        
        return temp;
        
        
    }
};