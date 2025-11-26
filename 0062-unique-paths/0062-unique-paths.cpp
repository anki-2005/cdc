class Solution {
public:
    int noofpath(int m,int n,vector<vector<int>>&cache){
    if(cache[m][n]!=-1) return cache[m][n];
    if(m==0 && n==0) cache[m][n]= 1;
    if(m==0 || n==0) cache[m][n]=1;
    else{
    int a=noofpath(m-1,n,cache);
    int b=noofpath(m,n-1,cache);
    cache[m][n]=a+b;
    }
    return cache[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>cache(m,vector<int>(n,-1));
        int ans=noofpath(m-1,n-1,cache);
        return ans;
    }
};