class Solution {
public:
    void power(vector<int> &nums,int idx,set<vector<int>> & st,vector<int> temp){
        if(idx< 0 ){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return ;
        }
        temp.push_back(nums[idx]);
        power(nums,idx-1,st,temp);
        temp.pop_back();
        power(nums,idx-1,st,temp);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        int n=nums.size();
        vector<int>temp;
        power(nums,n-1,st,temp);
        vector<vector<int>>v(st.begin(),st.end());
        return v;
    }
};