class Solution {
public:
   void dfs(vector<vector<int>>& adj , vector<int> & visited,int src){
      visited[src]=1;
      for(auto it: adj[src]){
          if(!visited[it]) dfs(adj,visited,it);
      }
      return ;
   }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<vector<int>>adj(n);
        for(auto &it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                cnt++;
            }
        }
        return cnt-1;
    }
};