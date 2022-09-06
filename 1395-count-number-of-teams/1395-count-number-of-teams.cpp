class Solution {
public:
    
    int recur(vector<int> a,int i,int prev,int count){
        if(count == 0)
            return 1;
        if(i == size(a))
            return 0;
        
        
        int notTake = 0,take = 0;
        notTake = recur(a,i+1,prev,count);
        if(prev<0 || a[prev]<a[i])
            take = recur(a,i+1,i,count-1);
        return take + notTake;
    }
    
    
    int memo(vector<int> a,int i,int prev,int count,vector<vector<vector<int>>>& dp){
        
        if(count == 0)
            return 1;
        if(i > size(a))
            return 0;
        
        if(dp[i][prev][count]!=-1)
            return dp[i][prev][count];

        int notTake = 0,take = 0;
        notTake = memo(a,i+1,prev,count,dp);
        if(prev==0 || a[prev-1]<a[i-1])
            take = memo(a,i+1,i,count-1,dp);
        return dp[i][prev][count] = take + notTake;
        
    }
    //tle 
    int tabu(vector<int> a){
        int n = size(a);
        vector<vector<vector<int>>> dp(n+2,vector<vector<int>>(n+1,vector<int>(4,0)));
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n;j++)
                dp[i][j][0] = 1;
        }
        
        
        
        for(int i=n;i>=1;i--){
            for(int prev=n-1;prev>=0;prev--){
                for(int count=1;count<4;count++){
                    int notTake = 0,take = 0;
                    notTake = dp[i+1][prev][count];
                    if(prev==0 || a[prev-1]<a[i-1])
                        take = dp[i+1][i][count-1];
                    dp[i][prev][count] = take + notTake;
                }
            }
                
        }
        
        return dp[1][0][3];
    }
    
    
//     int tabu(vector<int> a){
//         int n = size(a);
       
        
//         vector<vector<int>> dp_prev(vector<vector<int>>(n+1,vector<int>(4,)));
//         vector<vector<int>> pres(vector<vector<int>>(n+1,vector<int>(4,0)));
        
        
//         for(int i=n;i>=1;i--){
//             for(int prev=n-1;prev>=0;prev--){
//                 for(int count=1;count<4;count++){
//                     int notTake = 0,take = 0;
//                     notTake = dp[i+1][prev][count];
//                     if(prev==0 || a[prev-1]<a[i-1])
//                         take = dp[i+1][i][count-1];
//                     dp[i][prev][count] = take + notTake;
//                 }
//             }
                
//         }
        
//         return dp[1][0][3];
//     }
    
    
    
    int solut(vector<int> a){
        int n = size(a);
        vector<int> left(n,0),right(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i])
                    left[i]+=1;
            }
        }
        
        
        for(int i=n-1;i>=0;i--){
            for(int j = n-1;j>i;j--){
                if(a[i]>a[j])
                    right[i]+=1;
            }
        }
        
        int ct = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i])
                    ct+=left[j];
            }
        }
        
        
        for(int i=n-1;i>=0;i--){
            for(int j = n-1;j>i;j--){
                if(a[i]>a[j])
                    ct+=right[j];
            }
        }
        
        return ct;
    }
    
    
    int numTeams(vector<int>& a) {
        int n = size(a);
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(4,-1)));
        
        // int i = recur(a,0,-1,3);
        // vector<int> b = a;
        // reverse(b.begin(),b.end());
        // int j = recur(b,0,-1,3);
        
        // int i = memo(a,1,0,3,dp);
        // vector<int> b = a;
        // reverse(b.begin(),b.end());
        // vector<vector<vector<int>>> bp(n+1,vector<vector<int>>(n+1,vector<int>(4,-1)));
        // int j = memo(b,1,0,3,bp);
        
        // int i =tabu(a);
        // vector<int> b = a;
        // reverse(b.begin(),b.end());
        // int j = tabu(b);
        // return i+j;
        return solut(a);
    }
};