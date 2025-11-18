class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            int small=nums[i];
            int large=nums[i];
            for(int j=i;j<n;j++){
               small=min(small,nums[j]);
               large=max(large,nums[j]);
               sum=(sum+(large-small)%mod)%mod;
            }
        }
        return sum;
    }
};