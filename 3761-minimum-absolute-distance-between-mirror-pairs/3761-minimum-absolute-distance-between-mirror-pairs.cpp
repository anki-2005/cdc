class Solution {
public:
    int rever(int x){
        int rev = 0;
    while(x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map <int,int>mpp;
        
        int n = nums.size();
        
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            if(mpp.count(nums[i])){
                res=min(res,i-mpp[nums[i]]);
            }
            mpp[rever(nums[i])]=i;
        }
        return (res < INT_MAX) ? res :-1;
    }
};