class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0;
        int r=0;
        deque<long long> maxd;
        deque<long long>mind;
        long long cnt=0;
        long long cost=0;
        while(r<nums.size()){
            while(!maxd.empty() && maxd.back()< nums[r]){
                maxd.pop_back();
            }
            while(!mind.empty() && mind.back() > nums[r]){
                mind.pop_back();
            }
            maxd.push_back(nums[r]);
            mind.push_back(nums[r]);
            cost=(maxd.front()-mind.front())*(r-l+1);
            while(cost>k){
                if(mind.front()==nums[l]) mind.pop_front();
                if(maxd.front()==nums[l]) maxd.pop_front();
                l++;
                cost=(maxd.front()-mind.front())*(r-l+1);
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
};