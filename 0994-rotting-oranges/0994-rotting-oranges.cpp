class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
         int maxtime = -1;
        while(!q.empty()){
            int s=q.size();
            maxtime++;
            for(int i=0;i<s;i++){
                auto p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                // left
                if(y - 1 >= 0 && grid[x][y - 1] == 1){
                    grid[x][y - 1] = 2;
                    fresh--;
                    q.push({x, y - 1});
                }

                // RIGHT
                if(y + 1 < n && grid[x][y + 1] == 1){
                    grid[x][y + 1] = 2;
                    fresh--;
                    q.push({x, y + 1});
                }

                // UP
                if(x - 1 >= 0 && grid[x - 1][y] == 1){
                    grid[x - 1][y] = 2;
                    fresh--;
                    q.push({x - 1, y});
                }

                // DOWN
                if(x + 1 < m && grid[x + 1][y] == 1){
                    grid[x + 1][y] = 2;
                    fresh--;
                    q.push({x + 1, y});
                }

                }
    
            }
            return (fresh==0 )? maxtime  : -1; 
        }
};