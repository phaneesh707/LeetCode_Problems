class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        if(m.size()<2)
            return m.size();
        
        int maxi = 1,count = 1;
        for(auto it = m.begin();it!=m.end();it++){
          
            if(m.find(it->first+1)!=m.end()){
                count++;
                maxi = max(count,maxi);
            }else
                count = 1;
                
        }
        
        return maxi;
    }
};