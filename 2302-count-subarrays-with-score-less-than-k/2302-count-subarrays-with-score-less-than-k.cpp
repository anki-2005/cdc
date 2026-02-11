class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<long long>presum(n);
         presum[0]=nums[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+nums[i];
        }
        int l=0;
        int r=0;
        long long cnt=0;
        while(r<nums.size()){
          long long sum=presum[r]-(l>0 ?presum[l-1]:0);
           long long val=sum*(r-l+1);
           while(val>=k && l<=r){
             l++;
             sum=presum[r]-(l>0 ?presum[l-1]:0);
            val=sum*(r-l+1);
           }
            cnt+=(r-l+1);
           r++;
        }
        return cnt;
    }
};