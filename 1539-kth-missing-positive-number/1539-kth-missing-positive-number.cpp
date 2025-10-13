class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       for(auto it:arr){
        if(it>k){
            return k;
            break;
        }
        k++;
       }
       return k;
    }
};