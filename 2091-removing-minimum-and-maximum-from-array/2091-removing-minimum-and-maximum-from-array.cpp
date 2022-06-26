class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX,maxi = INT_MIN,minIdx = -1,maxIdx = -1,n=nums.size();
        if(n==1)
            return 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                maxIdx = i+1;
                    
            }
            if(nums[i]<mini){
                mini = nums[i];
                minIdx = i+1;
            }         
        }
        cout<<maxIdx<<minIdx;
     
        if(minIdx<=n/2 && maxIdx <=n/2)            
            return max(maxIdx,minIdx);
        else if(minIdx>=n/2 && maxIdx >= n/2)
            return n-min(maxIdx,minIdx)+1;
        else{
            int l = min(minIdx,maxIdx),r = min(n-minIdx,n-maxIdx)+1,mid = abs(minIdx-maxIdx);
            return min(l+r,min(l+mid,mid+r));     
        }
        
    }
};