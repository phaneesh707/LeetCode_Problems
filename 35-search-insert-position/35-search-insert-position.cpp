class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int low=0,high = nums.size()-1,mid,l,h,flag;
        while(low<high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        
        if(low==0){
            if(nums[0]>=target) flag =0 ;
            else flag=1;
        }else{
            if(nums[low]>=target) flag=low;
            else flag=low+1;
        }
        
        return flag;
    
                
    }
};