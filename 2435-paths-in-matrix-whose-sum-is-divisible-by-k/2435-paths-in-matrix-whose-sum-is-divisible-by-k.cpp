class Solution {
public:
long long md=1e9+7;
int path(vector<vector<int>> & v , int m, int n, int key , int k, vector<vector<vector<int>>>&memo){
    if(m<0 || n<0) return 0;
    key=(key+v[m][n])%k;
    if(m==0 && n==0) {
       if(key==0) return 1;
       else return 0;
    }
    if(memo[m][n][key]!=-1) return memo[m][n][key];
    int a=path(v,m,n-1,key,k,memo);
    int b=path(v,m-1,n,key,k,memo);
    return memo[m][n][key]=((a+b) % md);
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>memo(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return path(grid,m-1,n-1,0,k,memo);
    }
};