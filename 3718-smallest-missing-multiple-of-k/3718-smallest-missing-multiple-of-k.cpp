class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        int l= nums.size();
        int ans=-1;
        for(int i=1;i<=l;i++){
            if(st.find(i*k) == st.end()) {
                ans=i*k;
                break;
            }
        }
        if(ans ==-1) ans=k*(l+1);
        return ans;
    }
};