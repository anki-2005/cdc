class Solution {
public:
    int findparent(int u,vector<int>&parent){
        if (parent[u]==u) return u;
        return parent[u]=findparent(parent[u],parent);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>adj(n);
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            int r=stones[i][0];
            int c=stones[i][1];
            for(int j=i+1;j<n;j++){
                if(r==stones[j][0] || c==stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            int pu=findparent(i,parent);
            for(auto it:adj[i]){
                int pv=findparent(it,parent);
                if(pu!=pv) parent[pv]=pu;
            }
        }
        int cnt=0; 
        for(int i=0;i<n;i++){
            if(parent[i]!=i) cnt++;
        }
        return cnt;
    }
};