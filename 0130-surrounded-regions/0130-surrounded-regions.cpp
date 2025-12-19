class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m ;j++){
               if((i==0 || i==n-1 || j==0|| j==m-1) && board[i][j]=='O') {
                q.push({i,j});
                visited[i][j]=1;
                board[i][j] = '#';
            }
        }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
             // up
                if(i-1>=0 && board[i-1][j]=='O' && visited[i-1][j]==0){
                    board[i-1][j]='#';
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                }
                // down 
                if(i+1<n && board[i+1][j]=='O' && visited[i+1][j]==0){
                     board[i+1][j]='#';
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                }
                // right
                 if(j+1<m && board[i][j+1]=='O' && visited[i][j+1]==0){
                     board[i][j+1]='#';
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                }
                if(j-1 >=0 && board[i][j-1]=='O' && visited[i][j-1]==0){
                     board[i][j-1]='#';
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};