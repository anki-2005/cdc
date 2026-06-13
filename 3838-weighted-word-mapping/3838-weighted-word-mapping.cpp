
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        map<int ,int>mpp;
        for(int i=0;i<26;i++){
            mpp[i]=weights[i];
        }
        string ans="";
        int k=words.size();
        for(int i=0;i<k;i++){
            int sum=0;
            for(auto it:words[i]){
                sum+=mpp[it-'a'];
            }
            ans+=('a'+(25-(sum%26)));
        }
        return ans;
    }
};