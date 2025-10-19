class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int maxlen=0;
        vector<int>v(256,0);
        while(j<n){
            if(v[s[j]]==0){
                v[s[j]]=1;
                j++;
                maxlen=max(maxlen,j-i);
            }
            else{
                v[s[i]]=0;
                i++;
            }
        }
        return maxlen;
    }
};