class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int x=nums[i];
            while(x!=0){
                int r=x%10;
                sum=sum+r;
                x=x/10;
            }
            v.push_back({sum,nums[i]});
        }
        sort(v.begin(),v.end());
        int count=0;
        map<int,int>mpp;
        for(int i=0;i<v.size();i++){
            mpp[v[i].second]=i;
        }
        int i=0;
        while(i<v.size()){
                auto it=mpp.find(nums[i]);
                if(i!=it->second){
                    swap(nums[i],nums[it->second]);
                    count++;
                }
                else{
                    i++;
            }
        }
        return count;
    }
};