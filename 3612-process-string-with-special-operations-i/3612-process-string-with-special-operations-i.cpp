class Solution {
public:
    string processStr(string s) {
        string result;

        for(auto it:s){
            if(it >='a' && it<='z') result+=it;
            else if(it == '*') {
                if(!result.empty())result.pop_back();
            }
            else if(it == '#') result+=result;
            else{
                reverse(result.begin(),result.end());
            }
        }

        return result;
    }
};