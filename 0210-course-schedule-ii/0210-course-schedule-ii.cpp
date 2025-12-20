class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
    for(int i=0;i<n;i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
        queue<int>q;
    vector<int>ind(numCourses,0);
    for(auto i:adj){
        for(auto it:i){
            ind[it]++;
        }
    }
    for(int i=0;i<ind.size();i++){
        if(ind[i]==0) q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int i=q.front();
        q.pop();
        ans.push_back(i);
        for(auto it:adj[i]){
            ind[it]--;
            if(ind[it]==0) q.push(it);
        }
    }
    if(ans.size()==numCourses) return ans;
    else return {};
    }
};