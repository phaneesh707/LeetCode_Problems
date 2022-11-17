//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long a[], long long n)
    {
        return mergeSort(a,0,n-1);
        
    }
    
    
    long long mergeSort(long long a[],long long l,long long r){
        long long count  = 0;
        if(l<r){
            long long mid = (r+l)/2;
            count+=mergeSort(a,l,mid);
            count+=mergeSort(a,mid+1,r);
            count+=merge(a,l,mid,r);
        }
        return count;
        
    }
    
    
    long long merge(long long a[],long long l,long mid,long long r){
        long long i = l,j = mid+1,k  = 0,count=0;
        long long b[r-l+1];
        while(i<=mid && j<=r){
            if(a[i]<=a[j])
                b[k++] = a[i++];
            else{
                count+=(mid-i+1);
                b[k++] = a[j++];
            }
        }
        
        while(i<=mid) b[k++] = a[i++];
        while(j<=r) b[k++] = a[j++];
        
        
        for(long long i=l,k=0;k<r-l+1;i++,k++){
            a[i] = b[k];
        }
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends