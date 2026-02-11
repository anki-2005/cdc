class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        queue<int>q;
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(nums[i]>=0) {
                q.push(i);
                temp.push_back(nums[i]);
            }
        }
        int l=temp.size();
        if(l==0) return nums;
         k=k%l;
        reverse(temp.begin(),temp.begin()+k);
        reverse(temp.begin()+k,temp.end());
        reverse(temp.begin(),temp.end());
        for(auto &it:temp){
            nums[q.front()]=it;
            q.pop();
        }
        return nums;
    }
};