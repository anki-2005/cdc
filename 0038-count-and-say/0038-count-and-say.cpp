class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++){
            int count=1;
            string temp="";
            for(int j=0;j<ans.size();j++){
                 if(j+1<ans.size() && ans[j]==ans[j+1]) count++;
                 else{
                     temp=temp+to_string(count)+ans[j];
                     count=1;
                }
            }
            ans=temp;
        }
        return ans;
    }
};