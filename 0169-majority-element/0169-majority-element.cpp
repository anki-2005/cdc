class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        int cmn = nums[0] ;
        for(int i=0 ;i < n ;i++){
            if(cnt == 0){
                cmn=nums[i];
            }
            if(cmn == nums[i]) cnt++;
            else cnt--;
        }
        return cmn;
    }
};