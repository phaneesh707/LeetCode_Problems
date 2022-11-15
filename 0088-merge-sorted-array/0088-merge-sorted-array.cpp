class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int k = m,l = n;
//         int i=0,j=0;
//         while(i<m && j<n){
//             if(nums1[i]<=nums2[j]) 
//                 i++;
//             else{
//                 nums1.insert(nums1.begin()+i,nums2[j]);
//                 m++;
//                 j++;
//             }
//         }

//         while(j<n){
//             nums1[i] = nums2[j];
//             i++;
//             j++;
//         }

//         nums1.resize(k+l);
        
        
        
        int i = m-1,j = n-1,k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j])  
                nums1[k--] = nums1[i--];
             else  
                 nums1[k--] = nums2[j--];
        }
        while(j>=0)
            nums1[k--] = nums2[j--];

    }
};