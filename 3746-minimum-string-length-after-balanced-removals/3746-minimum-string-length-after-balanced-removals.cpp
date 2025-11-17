class Solution {
public:
    int minLengthAfterRemovals(string s) {
        vector<int>ch(2,0);
        for(auto it:s){
            ch[it-'a']++;
        }
        int k=abs(ch[0]-ch[1]);
        return k;
    }
};