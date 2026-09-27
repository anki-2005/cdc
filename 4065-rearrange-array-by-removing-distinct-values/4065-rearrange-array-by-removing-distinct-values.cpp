class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<int>ans;
        while(!mpp.empty()){
            vector<int>erase;
        for(auto &it:mpp){
            ans.push_back(it.first);
            it.second--;
            if(it.second==0) erase.push_back(it.first);
        }
        for(auto it: erase){
            mpp.erase(it);
        }
        }
        return ans;
    }
};