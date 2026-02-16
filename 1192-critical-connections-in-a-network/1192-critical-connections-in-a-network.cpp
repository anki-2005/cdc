class Solution {
public:
     int cnt=0;
    void critical(vector<vector<int>>&adj,int node,int parent,vector<int>&inserttime, vector<int>&leasttime,vector<int>&visited,vector<vector<int>>&ans) {
        inserttime[node]=cnt;
        leasttime[node]=cnt;
        cnt++;
        for(auto it:adj[node]){
            if(visited[it]==0) {
                visited[it]=1;
                critical(adj,it,node,inserttime,leasttime,visited,ans);
                leasttime[node]=min(leasttime[node],leasttime[it]);
                if(leasttime[it]>inserttime[node]){
                    ans.push_back({it,node});
                }
            }
            else if(visited[it]==1 && it!=parent){
                 leasttime[node]=min(leasttime[node],leasttime[it]);
               }
            }
              return ;
        }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto &it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(n,0);
        vector<int>inserttime(n,1e8);
        vector<int>leasttime(n,1e8);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                visited[i]=1;
                critical(adj,i,-1,inserttime,leasttime,visited,ans);
            }
        }
        return ans;
    }
};