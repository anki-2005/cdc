class Solution {
public:
    int split(vector<int>&nums,int sum){
        int noofsplit=1;
        int presum=0;
        for(int i=0;i<nums.size();i++){
            if(presum+nums[i]<=sum){
                presum+=nums[i];
            }
            else{
                noofsplit++;
                presum=nums[i];
            }
        }
        return noofsplit;
    }
    int splitArray(vector<int>& nums, int k) {
        int minsum=*max_element(nums.begin(),nums.end());
        int maxsum=0;
        for(int i=0;i<nums.size();i++) maxsum+=nums[i];
        while(maxsum>minsum){
            int mid=(maxsum+minsum)/2;
            int noofsplit=split(nums,mid);
            if(noofsplit>k){
                minsum=mid+1;
            }
            else if(noofsplit<=k){
                maxsum=mid;
            }
        }
        return minsum; 
    }
};