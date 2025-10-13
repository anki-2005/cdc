class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int maxel=*max_element(weights.begin(),weights.end());
        for(auto it :weights){
            sum+=it;
        }
        int l=maxel;
        int r=sum;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            int c=0;
            int temp=0;
            for(auto it:weights){
                temp+=it;
                if(temp>mid){
                    c++;
                    temp=it;
                }
                else if(temp==mid){
                    c++;
                    temp=0;
                }
            }
            if(temp>0) c++;
            if(c<=days){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};