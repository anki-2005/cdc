class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<long,long>mpp;
        for(auto it:costs){
            mpp[it]++;
        }
        long long cnt=0;
        for(auto it:mpp){
            if(it.first<=coins){
               if(it.first*it.second<=coins){
                coins-=it.first*it.second;
                cnt+=it.second;
               }
               else {
                cnt=cnt+(coins/it.first);
                break;
               }
            }
        }
        return cnt;
    }
};