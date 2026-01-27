class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int>q;
    vector<int>outd(n,0);
     for(int i=0;i<n;i++){
        outd[i]=graph[i].size();
     }
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        for(auto &it:graph[i]){
            adj[it].push_back(i);
        }
    }
    for(int i=0;i<outd.size();i++){
        if(outd[i]==0) q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int i=q.front();
        q.pop();
        ans.push_back(i);
        for(auto it:adj[i]){
            outd[it]--;
            if(outd[it]==0) q.push(it);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
    }
};