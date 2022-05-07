class Solution {
public:
    int flag = 0;
    void getSubs(vector<int> nums,vector<int> dummy,vector<vector<int>>& v,int i){
        if(i==nums.size()){
        
            for(int j=0;j<dummy.size();j++)
                v[flag].push_back(dummy[j]);
            flag++;
            return;
            
        }else if(i<nums.size()){
            dummy.push_back(nums[i]);
            getSubs(nums,dummy,v,i+1);
            dummy.pop_back();
            getSubs(nums,dummy,v,i+1);
            
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v(pow(2,nums.size()));
        vector<int> dummy;
        getSubs(nums,dummy,v,0);
        return v;
    }
};