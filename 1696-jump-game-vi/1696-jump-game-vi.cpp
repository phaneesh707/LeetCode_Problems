class Solution {
public:
    
    int recur(vector<int> a, int k,int idx){
        if(idx == 0)
            return a[0];
        
        int pts,maxi = INT_MIN;
        for(int i = 1;i<=k;i++){
            if(idx-i>=0){
                pts = a[idx] + recur(a,k,idx-i);
                maxi = max(maxi,pts);
            }     
        }
        return maxi;
    }
    
    
    int memo(vector<int> a, int k,int idx,vector<int> dp){
        if(idx == 0)
            return a[0];
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int pts,maxi = INT_MIN;
        for(int i = 1;i<=k;i++){
            if(idx-i>=0){
                pts = a[idx] + memo(a,k,idx-i,dp);
                maxi = max(maxi,pts);
            }     
        }
        return dp[idx] =  maxi;
    }
    
    //O(N^2) worst case when k = n;
    int tabu(vector<int> a, int k){
        vector<int> dp(a.size(),-1);
        dp[0] = a[0];
        for(int i = 1;i<a.size();i++){
            int maxi = INT_MIN;
            for(int j=1;j<=k && i-j>=0;j++){
                int pts = a[i] + dp[i-j];
                maxi = max(maxi,pts);
            }
            dp[i] = maxi; 
        }
        return dp[a.size()-1];
    }
    
    
    int opti(vector<int> a, int k){
        vector<int> dp(a.size(),-1);
        dp[0] = a[0];
        multiset<int> m({dp[0] = a[0]});
        for(int i = 1;i<a.size();i++){
            if(i>k)
                m.erase(m.find(dp[i-k-1]));
            dp[i] = a[i] + *m.rbegin();
            m.insert(dp[i]);
        }
        return dp.back();
        
    }
    
    int maxResult(vector<int>& nums, int k) {
        // return recur(nums,k,nums.size()-1);
        
        // vector<int> dp(nums.size(),-1);
        // return memo(nums,k,nums.size()-1,dp);
        
        
        // return tabu(nums,k);
        
        return opti(nums,k);
    }
};