class Solution {
public:
class disjoint
{
public:
    vector<int> rank;
    vector<int> parent;
    disjoint(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            rank.push_back(0);
            parent.push_back(i);
        }
    }
    int findparent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findparent(parent[u]);
    }
    void unionrank(int u, int v)
    {
        int pu = findparent(u);
        int pv = findparent(v);
        if (pu == pv)
            return;
        else
        {
            if (rank[pu] < rank[pv])
            {
                parent[pu] = pv;
            }
            else if (rank[pu] > rank[pv])
            {
                parent[pv] = pu;
            }
            else
            {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
};

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<vector<int>>adj(n);
        for(auto &it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        disjoint ds(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                ds.unionrank(i,it);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
           if(ds.findparent(i)==i) cnt++;
        }
        return cnt-1;
    }
};