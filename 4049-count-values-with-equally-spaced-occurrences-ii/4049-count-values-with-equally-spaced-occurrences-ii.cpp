class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
       map<int,int>mpp1;
       map<int,vector<int>>mpp2;
       for(int i=0;i<nums.size();i++){
         mpp1[nums[i]]++;
         mpp2[nums[i]].push_back(i);
       }
       int cnt =0;
       for(auto it:mpp1){
        if(it.second >=3){
           vector<int>temp = mpp2[it.first];
           int size = temp.size();
           int dis = temp[1]-temp[0];
           bool ans = true;
           for(int i=2;i<size;i++){
            if(temp[i]-temp[i-1]!=dis) ans = false;
           }
           if(ans) cnt++;
        }
       }
       return cnt;
    }
};