class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1) return r-l+1;
        int cnt =0;
        int i=0;
        while(pow(i,k)<=r){
            if(pow(i,k)>=l) cnt++;
            i++;
        }
        return cnt;
    }
};