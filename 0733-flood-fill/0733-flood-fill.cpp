class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int prevcolor=image[sr][sc];
        if(prevcolor == color) return image;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            image[x][y]=color;

            if(y - 1 >= 0 && image[x][y - 1] == prevcolor){
                    q.push({x, y - 1});
                }

                // RIGHT
            if(y + 1 < n && image[x][y + 1] == prevcolor){
                   
                    q.push({x, y + 1});
            }

                // UP
            if(x - 1 >= 0 && image[x - 1][y] == prevcolor){
                    
                   
                    q.push({x - 1, y});
            }

                // DOWN
            if(x + 1 < m && image[x + 1][y] == prevcolor){
                    
                  
                    q.push({x + 1, y});
            }  
        }
        return image;
    }
};