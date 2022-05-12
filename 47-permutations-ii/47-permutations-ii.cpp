// class Solution {
// public:
//     vector<vector<int>> v;
//     void permut(vector<int> nums,vector<int> dummy,int index,int start){
//         if(index == nums.size()){
//             v.push_back(dummy);
//             for(int i=0;i<dummy.size();i++)
//                 cout<<dummy[i]<<" ";
//             cout<<endl;
//             return;
//         }
        
        
//         for(int i=start;i<nums.size();i++){
//             dummy.push_back(nums[index]);
//             permut(nums,dummy,index+1,i);
//         }
        
//         // dummy.push_back(nums[index]);
//         // permut(nums,dummy,index+1);
//         // dummy.pop_back();
//         // permut(nums,dummy,index+1);
    
        
//     }
    
    
    
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
        
//         vector<int> dummy;
//         permut(nums,dummy,0,0);
//         return v;
//     }
// };



// class Solution {
// public:
//     set<vector<int>> v;
    
//     void swap(int& a,int& b){
//         int temp = a;
//         a = b;
//         b = temp;
//         return;
//     }
    
    
//     void permut(vector<int> nums,int index){
//         if(index == 1){
//             v.insert(nums);
//             for(int i=0;i<nums.size();i++)
//             cout<<nums[i]<<" ";
//             cout<<endl;
//             return;
//         }else{
            
//             permut(nums,index-1);
//             for(int i=0;i<index-1;i++){
//                 if(index%2)
//                     swap(nums[0],nums[index-1]);
//                 else
//                     swap(nums[i],nums[index-1]);
//                 permut(nums,index-1);
//             }
            
//         }
//     }
    
    
    
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
        
//         permut(nums,nums.size());
//         vector<vector<int>> V;
//         for(auto it = v.begin();it!=v.end();it++){
//             V.push_back(*it);
//         }
//         return V;
//     }
// };

class Solution {
public:
    set<vector<int>> v;
    
    void permut(vector<int> nums,vector<int> dummy,vector<int> visited){
        if(nums.size()==dummy.size()){
            v.insert(dummy);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                dummy.push_back(nums[i]);
                permut(nums,dummy,visited);
                dummy.pop_back();
                visited[i]=0;
            }
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> visited(nums.size(),0);
        vector<int> dummy;
        
        permut(nums,dummy,visited);
        vector<vector<int>> buffer;
        for(auto it = v.begin();it!=v.end();it++)
            buffer.push_back(*it);
        
        return buffer;
    }
};







