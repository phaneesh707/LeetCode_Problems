class Solution {
public:
    int trap(vector<int>& height) {
        int n = size(height);
        if(n<2) return 0;
        
        int res = 0,maxi=0;
        
        vector<int> prevMax(n,0),forwMax(n,0);
        
        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);
            prevMax[i] = max(maxi,height[i]);
        }
        maxi = height[n-1];
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,height[i]);
            forwMax[i] = max(maxi,height[i]);
        }
        
        for(int i=1;i<n-1;i++){
            int x = min(prevMax[i],forwMax[i]);
            if(x > height[i])
                res+= x-height[i];
            
        }
        
        return res;
        
    }
};