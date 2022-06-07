class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> temp;
        vector<int> a = {1};
        vector<int> b ={1,1};
        temp.push_back(a);
        if(numRows==1)
            return temp;
        temp.push_back(b);
        if(numRows==2)
            return temp;
        
        for(int i=2;i<numRows;i++){
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