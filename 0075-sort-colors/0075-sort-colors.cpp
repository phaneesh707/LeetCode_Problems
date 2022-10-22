class Solution {
public:
    
    // 1st approach 
    void f1(vector<int>& a){
        vector<int> count(3,0);
        for(auto it:a)
            count[it]++;
        int i=0,j=0;
        while(i<size(a)){
            while(i<size(a) && j<3 && count[j]){
                a[i] = j;
                i++;
                count[j]--;
            }
            j++;
        }
    }
    
    void sortColors(vector<int>& nums) {
        f1(nums);
    }
};