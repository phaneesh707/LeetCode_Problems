class Solution {
public:
    
    int spaceOpti(vector<int> a,int n,int fee){
        vector<int> prev(2);
        vector<int> pres(2);
      
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                int bought = 0,sold = 0, move = 0;
                if(buy==1)
                    bought = -a[idx] + prev[0];
                else
                    sold = a[idx] + prev[1]-fee;
                move = prev[buy];
                pres[buy] = max({bought,sold,move});
            }
            prev = pres;
        }
        return prev[1];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        return spaceOpti(prices,prices.size(),fee);
    }
};