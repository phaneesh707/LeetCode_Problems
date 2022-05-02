class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        auto start = nums.begin();
        auto last = nums.end()-1;
        while(start<last){
            while((*start)%2==0 && start<last)
                start++;
            
            while((*last)%2==1 && start<last)
                last--;
            
            int temp = *start;
            *start = *last;
            *last = temp;
        }
        
        return nums;
        
    }
};