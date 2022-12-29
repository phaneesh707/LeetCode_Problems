//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    vector<long long> res;
    queue<pair<long long,long long>> q;
    long long i = 0,j = 0;
    while(j<K){
        if(A[j]<0)
            q.push({A[j],j});
        j++;
    }
    j--;
    if(!q.empty())
        res.push_back(q.front().first);
    else
        res.push_back(0);
    while(j<N-1){
        i++;
        j++;
        if(!q.empty() && q.front().second<i)
            q.pop();
        if(A[j]<0)
            q.push({A[j],j});
        
        if(!q.empty())
            res.push_back(q.front().first);
        else
            res.push_back(0);
        
    }
   
    return res;
    
 }