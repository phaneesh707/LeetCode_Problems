class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // sort(stones.)
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int max1=stones[stones.size()-1];
            int max2=stones[stones.size()-2];
            
            stones.pop_back();
            stones.pop_back();
            if(max1!=max2)
                stones.push_back(max1-max2);
            cout<<max1<<max2<<"\n";
        }
        
        if(stones.size()==0)
            return 0;
        else
            return stones[0];
        
    }
};