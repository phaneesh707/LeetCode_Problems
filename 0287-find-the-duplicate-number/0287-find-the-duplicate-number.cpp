class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast = nums[0];
        //find intersection point 
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        //find entrance to cycle   
        fast = nums[0];
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};