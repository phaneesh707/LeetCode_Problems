class Solution {
public:
    
    void dfs(vector<vector<int>>& adj,vector<int>& visited,int node){
        visited[node] = 1;
        for(int it=0;it<adj.size();it++){
            if(adj[node][it] && !visited[it] && it!=node){
                dfs(adj,visited,it);
            }
        }
    }
    
    void bfs(vector<vector<int>>& adj,vector<int>& visited,int node){
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = size(isConnected),count = 0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(isConnected,visited,i);
            }
        }
        return count;
    }
};