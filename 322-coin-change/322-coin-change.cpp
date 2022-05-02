class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> minCoins(amount+1,INT_MAX);
        minCoins[0]=0;
    
        for(int i=0;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                if(j-coins[i]>=0 && minCoins[j-coins[i]]!=INT_MAX)
                    minCoins[j]=min(minCoins[j],minCoins[j-coins[i]]+1);  
            }
            
        }
        
        return minCoins[amount]!=INT_MAX?minCoins[amount]:-1;
        
    }
};