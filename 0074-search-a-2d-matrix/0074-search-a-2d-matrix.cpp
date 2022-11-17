class Solution {
public:
    
    bool binarySrc(vector<int>& a,int k){
        int l=0,h = size(a)-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(a[mid]==k)
                return true;
            else if(a[mid]>k)
                h = mid-1;
            else 
                l = mid+1;
        }
        return false;
    }
    
    
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int r = size(a),c = size(a[0]);
        for(int i=0;i<r;i++){
            if(binarySrc(a[i],target))
                return true;
        }
        return false;
    }
};