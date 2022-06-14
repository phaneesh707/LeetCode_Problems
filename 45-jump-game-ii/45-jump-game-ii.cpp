class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dummy(n,0);
        dummy[0] = 1;
        for(int i=0;i<n-1;i++){
            if(dummy[i]){
                if(dummy[n-1] || i+nums[i]>=n-1){
                    dummy[n-1] = dummy[i]+1;
                    break;
                }
                for(int j=1;j<=nums[i];j++){
                    if(!dummy[i+j])
                    dummy[i+j] = dummy[i]+1;
                }
            }
        }
        
        
        return dummy[n-1]-1;
    }
};