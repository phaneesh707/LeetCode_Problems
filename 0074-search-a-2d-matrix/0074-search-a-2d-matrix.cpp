class Solution {
public:
    //o(M*log(N))
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
    
    // o(log(m)*log(n))
    pair<int,int> binarySrc1(vector<int>& a,int k){
        int l=0,h = size(a)-1;
        while(h-l>1){
            int mid = (l+h)/2;
            if(a[mid]<k)
                l = mid;
            else 
                h = mid;
            
        }
        return {l,h};
    }
    
    
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int r = size(a),c = size(a[0]);
        // for(int i=0;i<r;i++){
        //     if(binarySrc(a[i],target))
        //         return true;
        // }
        // return false;
        
        vector<int> b(r);
        
        for(int i=0;i<r;i++)
            b[i] = a[i][0];
            
        pair<int,int> res = binarySrc1(b,target);
        if(binarySrc(a[res.first],target) || binarySrc(a[res.second],target))
            return true;
        return false;
        
        
        
    }
};