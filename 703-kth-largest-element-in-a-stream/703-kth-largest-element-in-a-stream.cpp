class KthLargest {
public:
    int l;
    vector<int> buf;
    KthLargest(int k, vector<int>& nums) {
        this->l = k;
        for(int i=0;i<nums.size();i++)
            this->buf.push_back(nums[i]);
        sort(this->buf.begin(),this->buf.end());
        
    }
    
    int add(int val) {
        // for(int i=0;i<this->buf.size();i++)
        //     cout<<this->buf[i];
        // cout<<"\n";
        
        int max = val,low=0;
        while(low<this->buf.size() && this->buf[low]<val)
            low++;
        // cout<<low;
        this->buf.insert(this->buf.begin()+low,val);
        return this->buf[this->buf.size() - this->l];   
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */