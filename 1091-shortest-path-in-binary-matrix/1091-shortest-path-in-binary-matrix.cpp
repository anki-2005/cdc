class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        typedef pair<int,pair<int,int>> node;
        priority_queue<node,vector<node>,greater<node>>minheap;
       if(grid[0][0]!=0|| grid[n-1][m-1]!=0) return -1;
       vector<vector<int>>visited(n,vector<int>(m,0));
        minheap.push({1,{0,0}});
        visited[0][0]=1;
        vector<int> dx={-1,-1,-1,0,0,1,1,1};
        vector<int> dy={-1,0,1,-1,1,-1,0,1};
        
        while(!minheap.empty()){
           auto p=minheap.top();
           minheap.pop();
           int dis=p.first;
           int i=p.second.first;
           int j=p.second.second;
           if(i==n-1 && j==m-1) return dis;
           for(int d = 0; d < 8; d++){
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 0 && !visited[ni][nj]){
                        visited[ni][nj]=1;
                        minheap.push({dis + 1, {ni, nj}});
                }
           }
        }
        return -1;
    }
};