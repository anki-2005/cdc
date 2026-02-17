class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int>mpp1;
        set<int>st;
        for(auto it: nums){
            mpp1[it]++;
        }
        map<int,int>mpp2;
        for(auto it:mpp1){
            mpp2[it.second]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mpp2[mpp1[nums[i]]]<2) {
                return nums[i];
            }
        }
        return -1;
    }
};