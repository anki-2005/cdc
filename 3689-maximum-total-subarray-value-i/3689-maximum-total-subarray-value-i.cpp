class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long  maxel=INT_MIN;
        long long  minel=INT_MAX;
        for(auto it:nums){
            if(it>maxel){
                maxel=it;
            }
            if(it<minel){
                minel=it;
            }
        }
        long long a=maxel-minel;
        return a*k;
    }
};