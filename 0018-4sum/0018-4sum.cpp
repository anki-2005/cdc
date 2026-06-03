class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int>v;
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                set<long long>mpp;
                for(int k=j+1;k<nums.size();k++){
                   long long n = (long long)target - ((long long)nums[i] + (long long)nums[j] + (long long)nums[k]);
                   if(mpp.find(n)!=mpp.end()){
                      v.push_back(nums[i]);
                      v.push_back(nums[j]);
                      v.push_back(n);
                      v.push_back(nums[k]);
                      sort(v.begin(),v.end());
                      s.insert(v);
                      v.clear();
                   }
                    mpp.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};