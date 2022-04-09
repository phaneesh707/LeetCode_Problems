class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //map to hold the frquency
        map<int,pair<int,int>> a;
        vector<int> sol;
        
        //heap to hold the get k frequenct elem in log(n) time
        priority_queue<pair<int,int>> pq;
        
        //counting frequency and adding a pair
        for(int i=0;i<nums.size();i++){
            a[nums[i]]=make_pair(++a[nums[i]].first,nums[i]);
            // cout<<a[nums[i]].first<<" "<<a[nums[i]].second<<"\n";
        }
        
            
         //consturting pq
        for(auto i=a.begin();i!=a.end();i++){
            pq.push(i->second);
            // cout<<i->first<<i->second.second<<"->"<<i->second.first<<"\n";
        }
        
        while(k--){
            sol.push_back(pq.top().second);
            pq.pop();
        }
        
            
        
        return sol;
    }
};