class Solution {
public:
    int recur(int n,int idx,vector<int> a){
        if(idx== n)
            return 1;
        int res=0;
        for(int i=1;i<=a[idx];i++){
            res = recur(n,idx+i,a);
            if(res) break;
        }
        return res;
    }
    
    
    int memo(int n,int idx,vector<int> a,vector<int>& dp){
        if(idx== n)
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        
        int res=0;
        for(int i=1;i<=a[idx];i++){
            res = recur(n,idx+i,a);
            if(res) break;
        }
        return dp[idx] =  res;
    }
    
    
    int tabu(vector<int> a){
        int n = a.size();
        vector<int> dp(n,0);
        dp[0] = 1;
        
        for(int i=0;i<n-1;i++){
            if(dp[i]==1){
                for(int j=1;j<=a[i];j++){
                    if(i+j<n)
                        dp[i+j]=1;
                }
            }
        }
        
        return dp[n-1];
    }
    
    
    //very optimized code
    bool opt(vector<int> a){
        int n = a.size();
        int minJump = 0;
        for(int i=n-2;i>=0;i--){
            minJump++;
            if(a[i]>=minJump)
                minJump = 0;
            
        }
        
        return !minJump;
    }
    
    bool canJump(vector<int>& nums) {
     
        // return recur(nums.size()-1,0,nums);
        // vector<int> dp(nums.size(),-1);
        // return memo(nums.size()-1,0,nums,dp);
        // return tabu(nums);
        return opt(nums);
    }
};