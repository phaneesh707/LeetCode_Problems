class Solution {
public:
    // recursion
    // void jump(vector<int> nums,int index,int& flag){
    //      if(index >= (nums.size()-1)){
    //          flag = 1;
    //          return;
    //      }   
    //     for(int i = 1;i<=nums[index];i++)
    //         jump(nums,index+i,flag);
    //     return;
    // }
    
    bool canJump(vector<int>& nums) {
       //  int flag = false;
       //  jump(nums,0,flag);
       // return flag;
        // if(!nums[0]) return 0;
        int n = nums.size();
        vector<int> dummy(n,0);
        dummy[0] = 1;
        for(int i=0;i<n-1;i++){
            if(dummy[i]){
                if(dummy[n-1] || i+nums[i]>=n-1){
                    dummy[n-1] = 1;
                    break;
                }
            
                for(int j=1;j<=nums[i];j++)
                    dummy[i+j] = 1;
            }
        }
        
        // for(int i=0;i<n;i++)
        //     cout<<dummy[i]<<" ";
        
        return dummy[n-1];
    }
};