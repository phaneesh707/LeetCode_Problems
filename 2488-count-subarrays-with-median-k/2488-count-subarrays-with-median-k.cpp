class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        
        int idx = -1,n=size(nums),sum = 0,res = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<k) nums[i] = -1;
            else if(nums[i]>k) nums[i] = 1;
            else if(nums[i]==k){
                idx = i;
                nums[i] = 0;
            }
        }
        if(idx == -1) return 0;
        map<int,int> m;
        for(int i=idx;i<n;i++){
            sum+=nums[i];
            m[sum]++;
        }
        sum = 0;
        for(int i=idx;i>=0;i--){
            sum+=nums[i];
            
            if(m.find(-sum)!=m.end())
                res+=m[-sum];
            if(m.find(-(sum)+1)!=m.end())
                res+=m[-(sum)+1];
        }
        
        return res;
        
        
        
    }
};