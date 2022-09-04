class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int sum = 0,n=size(a);
        for(auto it:a)
            sum+=it;
        int l = 0,r = sum-a[0],i=0;
        while(i<n){
            // cout<<l<<" "<<r<<endl;
            if(l==r)
                return i;
            
            l+=a[i];
            i++;
            if(i>=n)
                break;
            r-=a[i];
            
        }
        return -1;
    }
};