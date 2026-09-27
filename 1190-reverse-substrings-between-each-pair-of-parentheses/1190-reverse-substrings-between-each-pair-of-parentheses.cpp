class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack <int>st;
        for(int i=0 ; i< n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')'){
                int l = st.top();
                st.pop();
                reverse(s.begin()+l , s.begin()+i);
            }
        }
        string ans;
        for(auto it:s){
           if(isalpha(it)) ans+=it;
        }
        return ans;
    }
};