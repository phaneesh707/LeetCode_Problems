//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int a[], int l, int mid, int r)
    {
        int i=mid,j=r,k=r-l;
        vector<int> b(r-l+1);
        while(i>=l && j>mid){
            if(a[i]<=a[j])
                b[k--] = a[j--];
            else
                b[k--] = a[i--];
        }
        
        while(i>=l) b[k--] = a[i--];
        while(j>mid) b[k--] = a[j--];
        
        for(int i=l,k=0;k<b.size();i++,k++){
            a[i] = b[k];
        }
         
    }
    public:
    void mergeSort(int a[], int l, int r)
    {
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(a,l,mid);
            mergeSort(a,mid+1,r);
            merge(a,l,mid,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends