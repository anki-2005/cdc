class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='A'&& s[i]<='Z'){
                s[i]=s[i]+32;
                str+=s[i];
            }
            else if(s[i]>='a'&& s[i]<='z'){
                 str+=s[i];
            }
            else if(s[i]>='0'&&s[i]<='9'){
                 str+=s[i];
            }
        }
        string str1=str;
        reverse(str.begin(),str.end());
        if(str1==str){
            return true;
        }
        else{
            return false;
        }
    }
};