class Solution {
public:
    vector<vector<int>> res;
    void recur(vector<int> a,int i,int t,vector<int> d){
        if(t==0){
            if(size(d))
                res.push_back(d);
            return;
        }
        if(i==0){
            if(t%a[i]==0){
                while(t){
                    d.push_back(a[i]);
                    t-=a[i];
                }
                if(size(d))
                    res.push_back(d);
            }
            
            return;
        }
        
        
        
        recur(a,i-1,t,d);
        if(a[i]<=t){
            d.push_back(a[i]);
            recur(a,i,t-a[i],d);
        }
            
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<int> d;
        recur(cand,size(cand)-1,target,d);
        return res;
        
    }
};