class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue <int>pos;
        queue <int>neg;
        vector<int>ans;
        for(auto it:nums){
            if(it > 0)pos.push(it);
            else neg.push(it);
        }
        while(!pos.empty()){
            ans.push_back(pos.front());
            ans.push_back(neg.front());
            pos.pop();
            neg.pop();
        }
        return ans;
    }
};