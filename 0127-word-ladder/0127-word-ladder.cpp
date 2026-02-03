class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         set<string>s;
         s.insert(wordList.begin(),wordList.end());
         if(s.find(endWord)==s.end()) return 0;
         queue<pair<string,int>>q;
         q.push({beginWord,1});
         while(!q.empty()){
            auto [word,dis]=q.front();
            q.pop();
            if(word==endWord) return dis;
            int n=word.size();
            for(int i=0;i<n;i++){
                string str=word;
                for(char ch='a';ch<='z';ch++){
                    str[i]=ch;
                    if(s.find(str)!=s.end()){
                        q.push({str,dis+1});
                        s.erase(str);
                    }
                }
            }
         }
         return 0;
    }
};