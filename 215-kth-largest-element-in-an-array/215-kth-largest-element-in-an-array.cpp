class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       //  map<int,int> a;
       //  for(int i=0;i<nums.size();i++){
       //      a[nums[i]]++;
       //  }
       //  int count = 0;
       //  auto it = a.rbegin();
       // for(it = a.rbegin();it!=a.rend();it++){
       //     count+=it->second;
       //     if(count>=k)
       //        break;
       // }
       //  return it->first;
        
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};