class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
       unordered_map<long long ,long long >mpp;
       int n=nums.size();
      vector<long long>prefix(n+1,0);
       for(int i=0;i<nums.size();i++){
         prefix[i+1]=prefix[i]+nums[i];
       }
       long long maxsum=LLONG_MIN;
       vector<long long>best(k,LLONG_MAX);
       best[0]=0;
       for(int j=1;j<=nums.size();j++){
          int r=j%k;
          if(best[r] != LLONG_MAX){
            maxsum=max(maxsum,prefix[j]-best[r]);
          }
          best[r]=min(best[r],prefix[j]);
       }
       return maxsum;
    }
};