class Solution {
public:
    
    int sumOfDig(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        int maxi = -1;
        
        map<int,int> m;
        for(int i:nums){
            int s = sumOfDig(i);
            if(m.find(s)!=m.end())
                maxi = max(maxi,i+m[s]);
            m[s] = max(m[s],i);
            
        }
        
        return maxi;
    }
};