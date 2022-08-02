class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        
        int n = m.size(),count = 0,res;
            priority_queue<int,vector<int>,greater<int>> pq;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    pq.push(m[i][j]);
                }
            }
        while(count!=k){
            res = pq.top();
            pq.pop();
            count++;
        }
        return res;
    } 
};