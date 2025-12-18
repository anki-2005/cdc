class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            auto l=p.first;
            int dist=p.second;
            int i=l.first;
            int j=l.second;
            ans[i][j]=dist;
            int count=dist+1;
            if(i-1>=0 && visited[i-1][j]==0){
                    visited[i-1][j]=1;
                    q.push({{i-1,j},count});
                }
                // down 
             if(i+1<n && visited[i+1][j]==0){
                    visited[i+1][j]=1;
                    q.push({{i+1,j},count});
                }
                // right
             if(j+1<m && visited[i][j+1]==0){
                    visited[i][j+1]=1;
                    q.push({{i,j+1},count});
                }
            if(j-1 >=0 && visited[i][j-1]==0){
                    visited[i][j-1]=1;
                    q.push({{i,j-1},count});
            }
        }
        return ans;
    }
};