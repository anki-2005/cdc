class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        int n=nums.size();

        if(sum%2!=0) return false;

        int target=sum/2;

        vector<vector<bool>>t(n+1,vector<bool>(target+1));
        for(int i=0;i<=n;i++) t[i][0]=true;
        for(int i=1;i<=target;i++) t[0][i]=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(j>=nums[i-1]){

                    t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];

                }
                else {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][target];
    }
};