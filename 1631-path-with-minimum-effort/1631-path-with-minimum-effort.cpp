class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        typedef pair<int,pair<int,int>> node;
        priority_queue<node,vector<node>,greater<node>>minheap;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        minheap.push({0,{0,0}});
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        while(!minheap.empty()){
            auto p=minheap.top();
            minheap.pop();
            int dis=p.first;
            int i=p.second.first;
            int j=p.second.second;
            int val=heights[i][j];
            if(dis >dist[i][j]) continue;
            if(i==n-1 && j==m-1) return dis;
                for(int d = 0; d < 4; d++){
                  int ni = i + dx[d];
                  int nj = j + dy[d];
                    if(ni >= 0 && nj >= 0 && ni < n && nj < m){ 
                         int neweff=max(dis,abs(heights[ni][nj]-val));
                         if(  neweff< dist[ni][nj]){
                        dist[ni][nj]=neweff;
                        minheap.push({dist[ni][nj], {ni, nj}});}
                    }
                }
            } 
            return dist[n-1][m-1];
    }
};