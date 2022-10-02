class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> a(n+1,vector<int>(n+1,1e4)),res;
        for(int i=0;i<size(times);i++){
            int x=times[i][0],y=times[i][1];
            a[x][y] = times[i][2];
         }
    
        
        res = a;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i!=j)
                    res[i][j] = min(a[i][j],a[i][k]+a[k][j]);
                }
            }
            a=res;
        }
        
        
        int maxi = -1;
        for(int i=1;i<=n;i++){
            if(k!=i && a[k][i]>=10000)
                return -1;
            if(a[k][i]<1000)
                maxi = max(maxi,a[k][i]);
        }
        
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return maxi;
        
    }
};