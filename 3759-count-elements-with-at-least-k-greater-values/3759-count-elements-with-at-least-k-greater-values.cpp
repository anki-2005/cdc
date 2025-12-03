class Solution {
public:
    int countElements(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
        int cnt=0;
        int n=nums.size();
        if(k==0) return n;
        for(int i=0;i<n-1;i++){
            int greaterIdx = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            int greaterCount = n - greaterIdx;
            if(greaterCount >= k) cnt++;
        }
        return cnt;
    }
}; 