class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int n = cost.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if((i+1)%3==0) continue;
            sum+=cost[i];
        }
        return sum;
    }
};