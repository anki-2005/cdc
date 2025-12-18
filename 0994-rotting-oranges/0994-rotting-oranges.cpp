class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i< n;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]==1) count++;
                else if(grid[i][j]==2) {
                    q.push({i,j});
                }
            }
        }
        if(count==0) return 0;
        int time=-1;
        while(!q.empty()){
            int s=q.size();
            time++;
            for(int x=0;x<s;x++){
                pair<int,int>p = q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                // up
                if(i-1>=0 && grid[i-1][j]==1){
                    count--;
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                // down 
                 if(i+1<n && grid[i+1][j]==1){
                    count--;
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                // right
                 if(j+1<n && grid[i][j+1]==1){
                    count--;
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
                if(j-1 >=0 && grid[i][j-1]==1){
                    count--;
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
            }
        }
        if(count==0) return time;
        else return -1 ;
    }
};