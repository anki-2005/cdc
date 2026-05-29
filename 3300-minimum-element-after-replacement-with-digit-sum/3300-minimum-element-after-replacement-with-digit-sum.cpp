class Solution {
public:
    int sumofdigit(int k){
        int sum=0;
        while(k>0){
          sum+=k%10;
          k=k/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto it:nums){
            int val = sumofdigit(it);
            if(val<ans){
                ans=val;
            }
        }
        return ans;
    }
};