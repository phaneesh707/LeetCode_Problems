class Solution {
public:
//     int maxi = INT_MIN;
//     void score(vector<int>& card, int k,int start,int last,int sum){
//         if(k==0){
//             maxi = max(sum,maxi);
//             return;
//         }
//         score(card,k-1,start+1,last,sum+card[start]);
//         score(card,k-1,start,last-1,sum+card[last]);
            
//     }
    int maxScore(vector<int>& card, int k) {
        // score(cardPoints,k,0,cardPoints.size()-1,0);
        // return maxi;
        int sum=0,currSum=0,wsize=card.size()-k;
        for(int i=0;i<card.size();i++){
            sum+=card[i];
            if(i<wsize)
                currSum+=card[i];
        }
            
        int maxi=sum-currSum;
        for(int i=0;i<k;i++){
            currSum = currSum-card[i]+card[i+wsize];
            maxi=max(maxi,sum-currSum);
            
        }
        
        
        return max(maxi,sum-currSum);
        
        
        
    }
};