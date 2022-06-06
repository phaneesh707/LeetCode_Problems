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
        
        
        //for i th day to get max profit you had to buy it at min of 1 to i-1 th day
        int mini = prices[0];
        int maxi = 0;
        int profit;
        for(int i=1;i<prices.size();i++){
            profit=prices[i]-mini;
            maxi = max(profit,maxi);
            mini = min(prices[i],mini);
        }
        return maxi;
    }
};