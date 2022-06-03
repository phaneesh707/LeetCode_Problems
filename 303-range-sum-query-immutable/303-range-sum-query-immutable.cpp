class NumArray {
public:
    vector<int> a;
    NumArray(vector<int>& nums) {
        a=nums;
        for(int i=1;i<a.size();i++){
            a[i]+=a[i-1];
        }
    }
    
    int sumRange(int left, int right) {
       if(left == 0)
           return a[right];
        return a[right]-a[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */