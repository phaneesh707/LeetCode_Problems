class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,size(nums)-1);
    }
    
    long long  mergeSort(vector<int>& a,int l,int r){
        long long count = 0,mid;
        if(l<r){
            mid = (l+r)/2;
            count+=mergeSort(a,l,mid);
            count+=mergeSort(a,mid+1,r);
            count+=merge(a,l,mid,r);
        }
        return count;
    }
    
    
    long long merge(vector<int>& a,int l,int mid,int r){
        vector<int> b(r-l+1);
        
        int i=l,j = mid+1,k = 0,count = 0;
        for(int i=l;i<=mid;i++){
            while(j<=r && a[i]>2*(long)a[j])
                j++;
            count+=(j-(mid+1));
        }
        
        i=l;
        j = mid+1;
        while(i<=mid && j<=r){
            if(a[i]<=a[j])
                b[k++] = a[i++];  
            else 
                b[k++] = a[j++];
            
        }
        
        while(i<=mid) b[k++] = a[i++]; 
        while(j<=r) b[k++] = a[j++];
        
        for(int i=l,k=0;i<=r;i++,k++)
            a[i] = b[k];
        
        return count;
        
    }
    
};