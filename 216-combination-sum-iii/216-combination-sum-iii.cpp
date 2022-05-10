class Solution {
public:
    vector<vector<int>> v;
    
    void getSubs(vector<int> dig,vector<int> buffer,int k,int n,int index){
        if(index == dig.size() && buffer.size()==k){
            int sum = 0;
            for(int i=0;i<buffer.size();i++)
                sum+=buffer[i];
            
            if(sum == n)
                v.push_back(buffer);
            return;
        }else if(index < dig.size()){
                buffer.push_back(dig[index]);
                getSubs(dig,buffer,k,n,index+1);
                buffer.pop_back();
                getSubs(dig,buffer,k,n,index+1);
            }
                
            
        
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> dig ={1,2,3,4,5,6,7,8,9};
        vector<int> buffer;
        getSubs(dig,buffer,k,n,0);
        return v;
        
    }
};