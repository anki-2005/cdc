class Solution {
public:
    void traversal(vector<vector<int>>& isConnected , vector<int>&visited,int start){
       queue<int>q;
       q.push(start);
       while(!q.empty()){
        int node = q.front();
        q.pop();
        if(visited[node]==0){
            visited[node]=1;
            for(int i=0;i < isConnected[node].size();i++){
                if(i!=node && isConnected[node][i]==1){
                    q.push(i);
                }
            }
        }
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        int cnt=0;
        vector<int> visited(size,0);
        for(int i=0;i < size ;i++){
            if(visited[i]==0){
                traversal(isConnected,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};