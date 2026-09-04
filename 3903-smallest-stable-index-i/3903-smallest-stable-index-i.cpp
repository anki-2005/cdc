class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       deque<int>mindq;
        for(auto it:nums){
            while(!mindq.empty() && mindq.back() > it){
                mindq.pop_back();
            }
            mindq.push_back(it);
        }
        int maxel  = nums[0];
        for(int i =0;i<nums.size();i++){
            if(maxel < nums[i]){
                maxel = nums[i];
            }
            if((maxel-mindq.front()) <= k){
                return i ;
            }
            if(mindq.front() == nums[i]){
                mindq.pop_front();
            }
        }
        return -1; 
    }
};