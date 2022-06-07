class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp;
        vector<int> dummy;
        for(int i=0;i<=rowIndex;i++){
            dummy.resize(i+1,1);
            
            for(int j=0;j<i;j++){
                if(j!=0)
                    dummy[j] = temp[j] + temp[j-1];
            }
            temp.resize(i+1);
            temp = dummy;
            
        }
        return dummy;
        
    }
};