// class Solution {
// public:
    
//     int minCost(vector<int> cost,int n){
//         if(n==2)
//             return min(cost[0],cost[1]);
//         if(n==3)
//             return min(cost[0]+cost[2],cost[1]);
        
//         int left = minCost(cost,n-1)+cost[n-1];
//         int right = minCost(cost,n-2)+cost[n-2];
//         return min(left,right);
        
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
//         return minCost(cost,cost.size());
//     }
// };



class Solution {
public:
    
//     int minCost(vector<int> cost,int n){
//         if(n==2)
//             return min(cost[0],cost[1]);
//         if(n==3)
//             return min(cost[0]+cost[2],cost[1]);
        
//         int left = minCost(cost,n-1)+cost[n-1];
//         int right = minCost(cost,n-2)+cost[n-2];
//         return min(left,right);
        
//     }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // return minCost(cost,cost.size());

        int n = cost.size();
        
        if(n==2)
            return min(cost[0],cost[1]);
        if(n==3)
            return min(cost[0]+cost[2],cost[1]);
        
        vector<int> a(n+1,0);
        
        a[2]= min(cost[0],cost[1]);
        a[3]= min(cost[0]+cost[2],cost[1]);
        for(int i=4;i<=n;i++){
            int left = cost[i-1]+a[i-1];
            int right = cost[i-2]+a[i-2];
            a[i]=min(left,right);
        }
        
        
        return a[n];
        
        
        
    }
};