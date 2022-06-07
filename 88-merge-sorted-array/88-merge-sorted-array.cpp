class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j])
                temp.push_back(nums1[i++]);
            else
                temp.push_back(nums2[j++]);
            
        }
        
        if(i==m){
            while(j<n)
                temp.push_back(nums2[j++]);
        }else{
            while(i<m)
                temp.push_back(nums1[i++]);
        }
        
        for(i=0;i<m+n;i++)
            nums1[i]=temp[i];
        
    }
};