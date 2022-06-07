class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> temp(n+1,0);
        for(int i=1;i<=n;i++){
            if(i%2)
                temp[i]=temp[i-1]+1;
            else
                temp[i] = temp[i/2];
            
                
        }
        
        return temp;
    }
};