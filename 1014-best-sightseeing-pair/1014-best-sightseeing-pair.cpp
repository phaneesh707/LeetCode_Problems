class Solution {
public:
    
    //Time O(N) spcae O(1)
    //keep track of the elemnts which gives the highest value(value[i]+i) to maxPair
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxPair,maxVal;
        maxVal = max(values[0],values[1]+1);
        maxPair = values[0]+values[1]-1;
        
        for(int i=2;i<values.size();i++){
            maxPair = max(maxPair,maxVal + values[i]-i);
            maxVal = max(maxVal,values[i]+i);
        }
        return maxPair;
    }
};