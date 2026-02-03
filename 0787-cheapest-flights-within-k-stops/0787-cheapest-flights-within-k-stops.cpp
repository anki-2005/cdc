class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        int m=flights.size();
        for(int i=0;i<m;i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        typedef pair<int,pair<int,int>> node;
        priority_queue<node,vector<node>,greater<node>> minheap;
        vector<int>cost(n,1e9);
        minheap.push({0,{0,src}});
        cost[src]=0;
        while(!minheap.empty()){
            auto p=minheap.top();
            minheap.pop();
            int cnt=p.first;
            int price=p.second.first;
            int node=p.second.second;
            if(cnt > k) break;
            for(auto it:adj[node]){
                int newcost=it.second+price;
                if(newcost<cost[it.first]){
                    cost[it.first]=newcost;
                    minheap.push({cnt+1,{newcost,it.first}});
                }
            }
        }
        if(cost[dst]!=1e9) return cost[dst];
        else return -1;
    }
};