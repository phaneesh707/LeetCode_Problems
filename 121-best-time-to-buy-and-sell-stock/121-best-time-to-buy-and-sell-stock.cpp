class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Brute force - TLE
        // int max = 0;
        // for(int i=0;i<prices.size();i++){
        //     for(int j=i+1;j<prices.size();j++){
        //         if(prices[j]-prices[i]>max)
        //             max = (prices[j]-prices[i]);
        //     }
        // }
        
        vector<int> profit(prices.size(),0);
        int mini = prices[0];
        int maxi = 0;
        for(int i=1;i<prices.size();i++){
            profit[i]=prices[i]-mini;
            maxi = max(profit[i],maxi);
            mini = min(prices[i],mini);
        }
        return maxi;
    }
};