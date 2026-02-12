class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>>adj(n,vector<int>(n,1e8));
    for(int i=0;i<n;i++) adj[i][i]=0;
    for(auto &e:edges){
        adj[e[0]][e[1]]=e[2];
        adj[e[1]][e[0]]=e[2];
    }
    for(int via=0;via< n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][via] !=1e8 && adj[via][j]!=1e8){
                    adj[i][j]=min (adj[i][j],(adj[i][via]+adj[via][j]));
                }
            }
        }
    }
    int maxlen=INT_MAX;
    int ans;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(i!=j && adj[i][j]<=distanceThreshold){
                cnt++;
            }
        }
        if(cnt <= maxlen){
            maxlen=cnt;
            ans=i; 
        }
    }
    return ans;
    }
};