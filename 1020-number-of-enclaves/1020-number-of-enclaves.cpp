class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m ;j++){
               if((i==0 || i==n-1 || j==0|| j==m-1) && grid[i][j]==1) {
                q.push({i,j});
                visited[i][j]=1;
                grid[i][j] = -1;
               }
        }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
             // up
                if(i-1>=0 && grid[i-1][j]==1 && visited[i-1][j]==0){
                    grid[i-1][j]=-1;
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                }
                // down 
                if(i+1<n && grid[i+1][j]==1 && visited[i+1][j]==0){
                     grid[i+1][j]=-1;
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                }
                // right
                 if(j+1<m && grid[i][j+1]==1 && visited[i][j+1]==0){
                     grid[i][j+1]=-1;
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                }
                if(j-1 >=0 && grid[i][j-1]==1 && visited[i][j-1]==0){
                     grid[i][j-1]=-1;
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                }
        }
        int cnt=0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};