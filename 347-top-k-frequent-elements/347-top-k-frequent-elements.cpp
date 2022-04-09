class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,pair<int,int>> a;
        vector<int> sol;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++){
            a[nums[i]]=make_pair(++a[nums[i]].first,nums[i]);
            // cout<<a[nums[i]].first<<" "<<a[nums[i]].second<<"\n";
        }
        
            
          
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