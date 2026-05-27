class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        map<char,int>mpp1;
        for(int i=0;i<n;i++){
            if(isupper(word[i])) {
                if (!mpp1.count(word[i])) mpp1[word[i]]=i;
            }
        }
        map<char,int>mpp2;
        for(int i=0;i<n;i++){
            if(islower(word[i])) mpp2[word[i]]=i;
        }
        int ans =0;
        for(auto it:mpp2){
            int smallidx = it.second;
            if(mpp1.count(toupper(it.first))) {
                if(mpp1[toupper(it.first)] > smallidx) ans++;
            }
        }
        return ans;
    }
};