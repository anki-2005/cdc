class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>time(n+1,1e9);
        typedef pair<int,int> node;
        priority_queue<node,vector<node>,greater<node>>minheap;
        int m=times.size();
        for(int i=0;i<m;i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        minheap.push({0,k});
        time[k]=0;
        while(!minheap.empty()){
            auto [t,node]=minheap.top();
            minheap.pop();
            if(t > time[node]) continue;
            for(auto it:adj[node]){
                int newtime=t+it.second;
                if(newtime < time[it.first]){
                    time[it.first]=newtime;
                    minheap.push({newtime,it.first});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(time[i]==1e9) return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }
};