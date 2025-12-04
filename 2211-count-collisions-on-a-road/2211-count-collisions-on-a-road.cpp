class Solution {
public:
    int countCollisions(string directions) {
        int i;
        int ans=0;
        int n=directions.size();
        int left=0;
        int right=n-1;
        while(left < n){
            if(directions[left]=='L') left++;
            else break;
        }
        while(right>=0){
            if(directions[right]=='R') right--;
            else break;
        }
        while(left<=right){
            if(directions[left]!='S') ans++;
            left++;
        }
        return ans;
    }
};