class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int r;
        for( r=n-1; r>0 ;r--){
           if(nums[r]<=nums[r-1]) break;

        }
        return r;
    }
};