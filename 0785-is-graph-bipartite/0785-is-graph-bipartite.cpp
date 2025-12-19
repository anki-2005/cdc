class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<char>color(n,'w');
        queue<pair<int,char>>q;
        q.push({0,'r'});
        color[0]='r';
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int idx=p.first;
            int col=p.second;
            for(auto it : graph[idx]){
                if(color[it]!='w'){
                    if(color[it]==col) return false;
                }
                else{
                    if(col=='r') {
                        q.push({it,'b'});
                        color[it]='b';
                    }
                    else {
                        q.push({it,'r'});
                        color[it]='r';
                    }
                }
            }
        }
        return true;
    }
};