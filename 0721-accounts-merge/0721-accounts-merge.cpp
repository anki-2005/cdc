class Solution {
public:
    int findparent(int u,vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]=findparent(parent[u],parent);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mpp;
        int n=accounts.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            int k=accounts[i].size();
            for(int j=1;j<k;j++){
                if(mpp.find(accounts[i][j])==mpp.end())  mpp[accounts[i][j]]=i;
                else {
                    int k=findparent(mpp[accounts[i][j]],parent);
                    int l=findparent(i,parent);
                    if(k!=l) parent[l]=k;
                }
            }
        }
        unordered_map<int,vector<string>>mpp1;
        for(auto &it:mpp){
            int p=findparent(it.second,parent);
            mpp1[p].push_back(it.first);
        }
        vector<vector<string>>ans;
        for(auto it:mpp1){
            vector<string>temp;
            for(auto i:it.second){
                temp.push_back(i);
            }
            sort(temp.begin(),temp.end());
            temp.insert(temp.begin(),accounts[it.first][0]);
            ans.push_back(temp);
        }
        return ans;
    }
};