class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> temp(n+1,0);
        for(int i=1;i<=n;i++){
            if((i-1)&1 == 0)
                temp[i] = temp[i-1]+1;
            
            else{
                int n = i;
                int count = 0;
                while(n){
                    if(n & 1) 
                        count+=1;
                    n=n>>1;
                }
                temp[i]=count;
                
            }
                
        }
        
        return temp;
    }
};